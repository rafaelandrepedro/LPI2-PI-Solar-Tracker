#include "pwm.h"

void PWMChannelConfig(PWM_Port port){
	HAL_TIM_PWM_Start(port.timHandle, port.PWM_Pin);
}

void GPIOPortConfigOutput(GPIO_Port port){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = port.GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init((GPIO_TypeDef *)port.GPIOx, &GPIO_InitStruct);
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

void PWMSignedDutyCycle(PWM_Bus bus, int8_t dutyCycle){
	if(dutyCycle<-100||dutyCycle>100){
		return;
	}
	bus.pwm_Port.timHandle->Init.Period = 100;
	if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
	{
		Error_Handler();
	}
	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = abs(dutyCycle);
	GPIOPortConfigOutput(bus.gpio_Port);
	if(dutyCycle<0){
		sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
		HAL_GPIO_WritePin((GPIO_TypeDef *)(bus.gpio_Port.GPIOx), bus.gpio_Port.GPIO_Pin, GPIO_PIN_SET);
	}
	else{
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		HAL_GPIO_WritePin((GPIO_TypeDef *)(bus.gpio_Port.GPIOx), bus.gpio_Port.GPIO_Pin, GPIO_PIN_RESET);
	}
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	if (HAL_TIM_PWM_ConfigChannel(bus.pwm_Port.timHandle, &sConfigOC, bus.pwm_Port.PWM_Pin) != HAL_OK)
	{
		Error_Handler();
	}
	HAL_TIM_PWM_Start(bus.pwm_Port.timHandle, bus.pwm_Port.PWM_Pin);
}
