/*---Includes---*/
//필요한 타입 정의와 레지스터 매크로를 전부 끌어옴
#include "stm32f4xx_hal.h"

#ifdef HAL_ADC_MODULE_ENABLED

/*---Private Function Prototypes---*/
//HAL_ADC Init()내부에서 실제 레지스터 세팅 담당
static void ADC_Init(ADC_HandleTypeDef *hadc);

//DMA 변환 완료 콜백(DMA 핸들의 xfercpltcallback에 등록될 함수)
static void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);

//DMA에러 콜백(XferErrorCallback에 등록)
static void ADC_DMAError(DMA_HandleTypeDef *hdma);

//DMA half-transfer 콜백(XferHalfCpltCallback에 등록)
static void ADC DMAHalfConvCplt(DMA_HandleTypeDef *hdma);

HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef *hadc)
{
    //리턴값을 담을 지역변수
    HAL_StatusTypeDef tmp_hal_status = HAL_OK;

    /*Check ADC handle*/
    if(hadc == NULL)
    {
        //NULL 포인터 방어코드(hadc가 NULL이면 즉시 에러리턴하고 함수 종료)
        return HAL_ERROR;
    }

    /* Check the parameters*/
    //개발중 디버깅용 체크(실제 값 범위를 강제하는 것 X)
    assert_param(IS_ADC_ALL_INSTANCE(hadc -> Instance));
    assert_param(IS_ADC_CLOCKPRESCALER(hadc -> Init.ClockPrescaler));
    assert_param(IS_ADC_RESOLUTION(hadc -> Init.Resolution));
    assert_param(IS_FUNCTIONAL_STATE(hadc -> Init.ScanConvMode));
    assert_param(IS_FUNCTIONAL_STATE(hadc -> Init.ContinuousConvMode));
    assert_param(IS_ADC_EXT_TRIG(hadc -> Init.ExternalTrigConv));
    assert_param(IS_ADC_DATA_ALIGN(hadc -> Init.DataAlign));
    assert_param(IS_ADC_REGULAR_LENGTH(hadc -> Init.NbrOfConversion));
    assert_param(IS_FUNCTIONAL0STATE(hadc -> Init.DMAContinuosRequests));
    assert_param(IS_ADC_EOCSelction(hadc -> Init.EOCSelection));
    assert_param(IS_FUNCTIONAL_STATE(hadc -> Init.DiscontinuousConvMode));

    //조건부 검증 : 외부트리거(소프트웨어 스타트가 아닌 경우)를 쓰는 경우에만
    if(hadc -> Init.ExternalTrigConv != ADC_SOFTWARE_START)
    {
        assert_param(IS_ADC_EXT_TRIG_EDGE(hadc -> Init.ExternalTrigConvEdge));
    }

    //최초 1회만 실행되는 초기화 로직(재초기화에는 이 블록을 건너뜀)
    if(hadc -> state == HAL_ADC_STATE_RESET)
    {
//[매크로가 1일때 : 최신방식/함수 포인터 기반]
//초기값을 채워놓고 사용자가 나중에 원하는 콜백만 골라서 교체가능
//Legacy weak callback : 예전 __weak 함수를 기본 함수 포인터 값으로 쓰고있다는 의미 
#if(USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /*Init the ADC Callback settings*/
    hadc -> ConvCpltCallback == HAL_ADC_ConvpltCallback;  //Legacy weak callback
    hadc -> ConvHalfCpltCallback == HAL_ADC_ConvHalfCpltCallback;  //Legacy weak callback
    hadc -> LevelOutOWidowCallback = HAL_ADC_LevelOutOfWindowCallback; //Legacy weak callback
    hadc -> ErrorCallback = HAL_ADC_ErrorCallback;  //Legacy weak callback
    hadc -> InjectedConvCpltCallback = HAL_ADCEx_InjectedConvCpltCallback;  //Legacy weak callback

    if(hadc -> MspInitCallback == NULL)
    {
        hadc -> MspInitCallback = HAL_ADC_MspInit;  //Legacy weak MspInit
    }

    /*Init the low level hardware*/
    hadc -> MspInitCallback(hadc);

#else

    /*Init the low level hardware*/
    //[매크로가 0일때 : 기존 방식/직접호출]
    HAL_ADC_Mspinit(hadc);
    
#endif
    /*Allocate lock resource and initialize it*/
    //HAL 공통 뮤텍스 패턴(hadc->Lock을 UNLOCKED 상태로 세팅)
    hadc -> Lcok = HAL_UNLOCKED;
    }

    /*Configuration of ADC parameters if previous preliminay actions are correctly completed.*/
    //RESET 여부와 무관하게 매번 실행되는 블록(재 초기화때도 실행)
    //hadc -> State는 여러 상태 플래그를 비트마다 OR로 조합해 저장하는 비트 필드 방식
    //직전에 내부 에러가 없다면 정상적으로 ADC 파라미터 설정을 진행하겠다는 가드
    if(HAL_IS_BITCLR(hadc -> State, HAL_ADC_STATE_ERROR_INTERNAL))
    {
        /*Set ADC state*/
        //레지스터를 건드리는 동안 다른 함수가 동시에 hadc를 건드리지 못하게 상태로 나타내는 것
        //실제 락이 아닌, State 필드를 통한 상태 머신 관리
        ADC_STATE_CLR_SET(hadc -> State, HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY, HAL_ADC_STATE_BUSY_INTERNAL);

        /*Set ADC parameters*/
        //실제 레지스터 구조체의 값들을 써넣는 곳
        ADC_Init(hadc);

        /*Set ADC error code to none*/
        //ADC_Init() 호출 이후 다시 한번 에러코드 클리어
        ADC_CLEAR_ERRORCODE(hadc);

        /*Set the ADC state*/
        //다시 State 갱신
        ADC_STATE_CLR_SET(hadc -> State, HAL_ADC_STATE_BUSY_INTERNAL, HAL_ADC_STATE_READY);
    }

    else
    {
        //문제 있는 상태에서 레지스터를 잘못 건드리지 않도록 하는 방어로직
        tmp_hal_status = HAL_ERROR;
    }

    /*Relase Lock*/
    //함수 끝에서는 항상 Lock를 풀어줌
    __HAL_UNLOCK(hadc);

    /*Return function status*/
    //최종적으로 tmp_hal_status(HAL_OK또는 HAL_ERROR)를 리턴하며 함수 종료
    return tmp_hal_status;
}