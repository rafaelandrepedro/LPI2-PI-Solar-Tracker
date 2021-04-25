#include "pwm.h"

void PWMChannelConfig(PWM_Port port){
	HAL_TIM_PWM_Start(port.timHandle, port.PWM_Pin);
}

void PWMDutyCycle(PWM_Port port, uint8_t dutyCycle){
	if(dutyCycle>100){
		return;
	}
	port.timHandle->Init.Period = 100;
	if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
	{
		Error_Handler();
	}
	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = dutyCycle;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if (HAL_TIM_PWM_ConfigChannel(port.timHandle, &sConfigOC, port.PWM_Pin) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_TIM_PWM_Start(port.timHandle, port.PWM_Pin);
}
