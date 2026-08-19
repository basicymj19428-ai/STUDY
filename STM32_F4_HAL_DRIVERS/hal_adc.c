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