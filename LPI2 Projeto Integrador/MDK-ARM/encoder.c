#include "gpio.h"
void EXTIConfig(GPIO_Port port){				//W.I.P.
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = port.GPIO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init((GPIO_TypeDef*)(port.GPIOx), &GPIO_InitStruct);
	
	IRQn_Type interruptLine;
	switch(port.GPIO_Pin){
		case GPIO_PIN_0:
			interruptLine=EXTI0_IRQn;
			break;
		case GPIO_PIN_1:
			interruptLine=EXTI1_IRQn;
			break;
		case GPIO_PIN_2:
			interruptLine=EXTI2_IRQn;
			break;
		case GPIO_PIN_3:
			interruptLine=EXTI3_IRQn;
			break;
		case GPIO_PIN_4:
			interruptLine=EXTI4_IRQn;
			break;
		case GPIO_PIN_5:
		case GPIO_PIN_6:
		case GPIO_PIN_7:
		case GPIO_PIN_8:
		case GPIO_PIN_9:
			interruptLine=EXTI9_5_IRQn;
			break;
		case GPIO_PIN_10:
		case GPIO_PIN_11:
		case GPIO_PIN_12:
		case GPIO_PIN_13:
		case GPIO_PIN_14:
		case GPIO_PIN_15:
			interruptLine=EXTI15_10_IRQn;
	}
	
	
	HAL_NVIC_SetPriority(interruptLine, 1, 0);
  HAL_NVIC_EnableIRQ(interruptLine);
}
	
	//









	

	
	
