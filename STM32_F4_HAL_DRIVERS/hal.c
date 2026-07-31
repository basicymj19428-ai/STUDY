/*---Includes---*/
//HAL의 핵심 초기화/공통 기능(HAL_Init, SysTick, Tick 관리 등)을 담당하는 모듈

//STM32F4 HAL 라이브러리 전체를 포함하는 최상위 헤더
//내부적으로 각 주변 장치별 HAL 헤더들을 include
#include "stm32f4XX_hal.h"