/*---Includes---*/
//HAL의 핵심 초기화/공통 기능(HAL_Init, SysTick, Tick 관리 등)을 담당하는 모듈

//STM32F4 HAL 라이브러리 전체를 포함하는 최상위 헤더
//내부적으로 각 주변 장치별 HAL 헤더들을 include
#include "stm32f4XX_hal.h"

/*---이 파일에서만 쓰는 private구조체/typedef 정의 영역---*/
/*---이 파일에서만 쓰는 private 매크로 상수 정의 영역---*/

//버전의 메인번호 = 1(최종 32비트 버전 코드 중 상위 8비트 [31:24]를 차지)
#define __STM32F4xx_HAL_VERSION_MAIN (0x01U)  /*!< [31:24] main version*/

//버전의 서브1(마이너) 번호 = 8(32비트중 [23:16] 비트 위치르 차지)
#define __STM32F4xx_HAL_VERSION_SUB1 (0x08U)  /*!< [23:16] sub1 version*/

//버전의 서브2(패치)번호 = 5(32비트 중 [15:8]비트 위치를 차지)
#define __STM32F4xx_HAL_VERSION_SUB2 (0x05U)  /*!< [15:8] sub2 version*/

//32비트중 최하위 [7:0]비트 위치를 차지
//RC 번호 = 0 : 정식 릴리즈를 의미(0이 아니면 개발/베타 버전)
#define __STM32F4xx_HAL_VERSION_RC (0x00U)  /*!< [7:0] release candidate*/

//MAIN=01, SUB1=08, SUB2=05, RC=00 ->V1.8.5버전
//런타임에 HAL_GetHalVersion() 함수로 조회가능
#define __STM32F4xx_HAL_VERSION ((__STM32F4xx_HAL_VERSION_MAIN << 24U)\
                                 (__STM32F4xx_HAL_VERSION_SUB1 << 16U)\
                                 (__STM32F4xx_HAL_VERSION_SUB2 << 8U)\
                                 (__STE32F4xx_HAL_VERSION_RC))

//MCU의 고유 ID 레지스터중 DEV_ID(칩 종류를 식별하는 필드) 부분만 추출하기 위한 마스크
#define IDCODE_DEVID_MASK 0x00000FFFU  

/*---RCC레지스터 비트 밴딩 영역 주소로 접근하기 위한 매크로들이 시작되는 구역---*/

//상대 오프셋 값을 계산
//SYSCFG가 PERIPH_BASE로 부터 얼마나 떨어진 위치에 있는지를 구함
#define SYSCFG_OFFSET (SYSCFG_BASE - PERIPH_BASE)

/*---SYSCFG_MEMRMP 레지스터(메모리 리매핑 설정 레지스터)관련 비트 밴딩 매크로 시작---*/
/*---UFB_MODE 비트하나를 위한 alias word 주소를 정의---*/
//UFB_MODE = User Bank swap/Flash mode 관련 비트, 특정 메모리 리매핑 옵션

//MEMRMP 레지스터도 SYSCFG 주변 장치에 속해있음
//레지스터가 SYSCFG 안에 있어 오프셋도 SYSCFG와 동일
#define MEMRMP_OFFSET  SYSCFG_OFFSET

//UFB_MODE 비트가 레지스터 내에서 몇번째 비트인지를 가져옴
//SYSCFG_MEMRMP_UFB_MODE_Pos : CMSIS 헤더에서 정의된값
#define UFB_MODE_BIT_NUMBER  SYSCFG_MEMRMP_UFB_MODE_Pos

//PERIPH_BB_BASE : 주변장치 비트 밴딩 alias 영역의 시작 주소
//(uint32_t)로 캐스팅 해서 최종적으로 주소값(정수)으로 확정
#define UFB_MODE_BB  (uint32_t)(PERIPH_BB_BASE + (MEMRMP_OFFSET * 32U) + (UFB_MODE_BIT_NUMBER * 4U))

/*---SYSCFG_CMPCR 레지스터 (I/O 컴펜세이션 셀 제어 레지스터)관련 밴딩매크로 시작---*/
/*---CMP_PD비트(컴펜세이션 셀 Power-Down비트) 하나를 위한 alias word 주소를 정의---*/

//CMPCR 레지스터의 SYSCFG 내부 오프셋이 0x20이라는 뜻
#define CMPCR_OFFSET (SUSCFG_OFFSET + 0x20U)

//CMP_PD비트가 CMPCR 레지스터 내에서 몇번째 비트인지 가져옴(CMSIS헤더에 정의된값)
#define CMP_PD_BIT_NUMBER  SYSCFG_CMPCR_CMP_PD_Pos

//CMP_PD 비트하나만을 가리키는 비트 밴딩 alias 주소를 계산
#define CMPCR_CMP_PD_BB  (uint32_t)(PERIPH_BB_BASE + (CMPCR_OFFSET * 32U) + (CMP_PD_BIT_NUMBER * 4U))


/*---SYSCFG_MCHDLYCR 레지스터(멀티채널 딜레이제어 레지스터)관련 비트 밴딩 매크로---*/
/*---BSCKSEL 비트 하나를 위한 alias word 주소를 정의---*/

//MCHDLYCR 레지스터는 SYSCFG 베이스로부터 0x30(=48바이트) 떨어진 위치에 있음
#define MCHDLYCR_OFFSET  (SYSCFG_OFFSET + 0x30U)

//BSCKSEL비트가 MCHDLYCR 레지스터 내에서 몇번째 비트인지 가져옴
#define BSCKSEL_BIT_NUMBER  SYSCFG_MCHDLYCR_BSCKSEL_Pos

//BSKCSEL 비트 하나만을 가리키는 alias 주소 완성
#define MCHDLYCR_BSCKSEL_BB  (uint32_t)(PERIPH_BB_BASE + (MCHDLYCR_OFFSET * 32U) + (BSCKSEL_BIT_NUMBER * 4U))

/*---이 파일에서만 쓰는 private 매크로(함수형 매크로 등) 정의 영역---*/

/*---이 파일에서만 쓰는 private 전역 변수 정의 영역---*/

//__IO : volatile을 의미하는 CMSIS 매크로(#define __IO volatile)
//인터럽트(SysTick_Handler)에서 계속 갱신되고 다른코드에서 읽음 
//컴파일러가 최적화로 값을 캐싱하지 않고 매번 실제 메모리를 읽도록 강제
__IO uint32_t uwTick;  //틱카운터 변수

//SysTick 인터럽트의 우선순위값을 저장하는 변수(초기값을 일부로 존재할수 없는 값으로 세팅)
uint32_t uwTickPrio = (1UL << __NVIC_PRIO_BITS);

//틱(uwTick)이 증가하는 주파수(빈도)를 저장하는 변수
//HAL_TickFreqTypeDef는 열거형(enum)타입(HAL_SetTickFreq() 함수로 나중에 주파수 변경가능)
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;  //1KHz

/*---이 파일 내부에서만 쓰는 private 함수들의 프로토타입 선언 영역---*/

/*---이 파일에서 실제로 구현하는 함수들이 시작되는 지점을 알리는 구획주석---*/
HAL_StatusTypeDef HAL_Init(void)
{
//컴파일타임설정(stm32f4xx_hal_conf.h)에서 명령어 캐시를 켜기로 했다면(1) Flash 명령어 캐시를 활성화
//CPU가 같은 코드를 반복 실행할때 Flash 접근없이 캐시에서 바로 읽어 속도 향상
#if(INSTRUCTION_CACHE_ENABLE != 0U)  
    __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
#endif

//데이터 캐시 : 조건부 활성화 -> 상수 데이터(const 배열 등) 반복 접근시 속도 향상
#if(DATA_CACHE_ENABLE != 0U)
    __HAL_FLASH_DATA_CACHE_ENABLE();
#endif

//프리페치 버퍼 활성화 : CPU가 다음 명령어를 미리 Flash에서 읽어와 대기시간 줄임
#if(PREFETCH_ENABLE != 0U)
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif

    //Cortex-M의 NVIC 우선순위를 그룹 우선순위 4비트/서브우선순위 0비트로 설정
    //선점 우선순위만 0~15까지 세밀하게 나누고 서브 우선순위 안쓰겠다는 뜻
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    //SysTick 타이머를 1ms 주기로 설정(인터럽트 우선순위를 TICK_INT_PRIORITY로 지정)
    //PLL등 외부 클럭 설정전이라 시스템 클럭 = 리셋 직후 기본값이 내부 HSI(16MHz) 상태
    HAL_InitTick(TICK_INT_PRIORITY);

    //사용자가 stm32f4xx_hal_msp.c에 구현해야 하는 저수준 하드웨어 초기화 콜백
    //__weak로 선언되어 있어서 사용자가 재정의 안하면 빈함수(아무동작 없음)로 링크
    //보편적으로 클럭소스(HSE 등) 활성화, 일부 GPIO 초기 설정등을 함
    HAL_MspInit();

    //모든 과정이 끝나면 HAL_OK 반환
    return HAL_OK;
}

//HAL의 공통부분을 역초기화하고 SysTick도 멈추는 함수
HAL_StatusTypeDef HAL_DeInit(void)
{
    /*APB1 버스에 연결된 모든 주변장치(TIM2~7, UART2/3, I2C 1~3, SPI2/3 등)를
    강제로 리셋 상태로 만들었다가(FORCE) 다시 풀어줌(RELEASE)*/
    //순서대로 호출해야 리셋 펄스를 준 효과가 남
    __HAL_RCC_APB1_FORCE_RESET();
    __HAL_RCC_APB1_RELEASE_RESET();

    //APB2버스 주변장치(TIM1/8, USART1/6, SPI1, ADC, SUSCFG 등) 리셋
    __HAL_RCC_APB2_FORCE_RESET();
    __HAL_RCC_APB2_RELEASE_RESET();

    //AHB1 버스 주변장치(GPIO A ~ H, DMA 1/2, CRC등) 리셋
    __HAL_RCC_AHB1_FORCE_RESET();
    __HAL_RCC_AHB1_RELEASE_RESET();

    //AHB2 버스 주변장치(USB OTG FS, RNG, 카메라 인터페이스 등) 리셋
    __HAL_RCC_AHB2_FORCE_RESET();
    __HAL_RCC_AHB2_RELEASE_RESET();

    //AHB3 버스 주변장치(FMC/FSMC 외부 메모리 컨트롤러 등) 리셋
    //APB1, APB2, AHB1, AHB2, AHB3에 연결된 거의 모든 주변장치를 순서대로 초기상태로 되돌림
    //단 RCC자체나 코어 클럭 설정, GPIO 자체의 리셋등은 대상이 아님
    __HAL_RCC_AHB3_FORCE_RESET();
    __HAL_RCC_AHB3_RELEASE_RESET();

    //HAL_MspInit()의 반대 짝 - 사용자가 stm32f4xx_hal_msp.c에 구현하는 __weak 콜백
    //사용자가 커스텀으로 설정했던 클럭/GPIO 등을 되돌리는 역할
    HAL_MspDeInit();

    //항상 성공(HAL_OK)반환
    return HAL_OK;
}

//stm32f4xx_hal.c에 있는 함수는 빈껍데기(절대 직접 수정 x)
//사용자는 stm32f4xx_hal_msp.c에 같은 이름의 함수를 다시 작성하면 링커에 의해 채택
__weak void HAL_MspInit(void)
{
}

//stm32f4xx_hal.c의 빈함수는 건드리지 않고 필요하면 stm32f4fxx_hal_msp.c에 실제 구현함
__weak void HAL_MspDeInit(void)
{
}

__weak HAL_StatusTypeDef HAL_InitTic(uint32_t TickPriority)
{
    //SysTick 타이머의 리로드값을 계산해서 세팅하고 SysTick을 활성화
    //1000U / uwTickFreq : 틱 주기가 몇 ms인지를 계산
    //SystemCoreClock : 현재 CPU 클럭 주파수[Hz],uwTickFreq : 틱 주파수(1kHz = 1ms 마다 틱)
    if(HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
    {
        return HAL_ERROR;  //실패시 즉시 HAL_ERROR 반환하고 함수 종류ㅛ
    }

    //전달받은 TickPriority값이 유효한 범위 안인지 먼저 검증
    //(1UL << __NVUIC_PRIO_BITS) : MCU가 지원하는 우선순위의 최대 개수
    if(TickPriority < (1UL << __NVUIC_PRIO_BITS))
    {
        //SysTick_IRQn의 선점 우선순위를 TickPriority로 서브우선순위는 0으로 설정
        HAL_NVIC_SetPriority(SysTick IRQn, TickPriority, 0U);
        
        //전역 변수에 실제 적용된 우선순위를 저장(설정이 유효하게 완료)
        uwTickPrio = TickPriority;  
    }
    else
    {
        //범위를 벗어나면(잘못된 값이 들어오면) HAL_ERROR 반환
        return HAL_ERROR;
    }

    //SysTick 설정 + 우선순위 설정이 모두 성공하면 HAL_OK 반환
    return HAL_OK;
}

__weak void HAL_IncTick(void)
{}