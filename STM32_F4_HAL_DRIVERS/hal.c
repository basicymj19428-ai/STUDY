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

/*---RCC레지스터 비트 밴딩 영역 주소로 접근하기 위한 매크로들이 시작되는 구역*/

//상대 오프셋 값을 계산
//SYSCFG가 PERIPH_BASE로 부터 얼마나 떨어진 위치에 있는지를 구함
#define SYSCFG_OFFSET (SYSCFG_BASE - PERIPH_BASE)