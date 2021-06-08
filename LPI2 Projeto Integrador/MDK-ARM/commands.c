#ifndef _commands_H
#define _commands_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "gpio.h"
#include "adc.h"
/**
  * @brief  Changes the pins state to output
  * @param	command		command string
	* 	@arg	portAdress		port adress where the pins are located (GPIOA->0, GPIOB->1 ...)
	*		@arg	pinSetting		binary position (mask) of the bits that need to be changed
	* @retval	none
  */
void makePortPinOutput(uint32_t portAdress, uint32_t pinSetting){
		GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	GPIO_InitStruct.Pin = pinSetting;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init((GPIO_TypeDef *)(portAdress*0x400+AHB1PERIPH_BASE), &GPIO_InitStruct);
	
}
/**
  * @brief  Writes digital outputs to output ports
  * @param	command		command string
	* 	@arg	portAdress		port adress where the pins are located (GPIOA->0, GPIOB->1 ...)
	*		@arg	pinSetting		binary position (mask) of the pins that need to be written
	*		@arg	pinValues			values that are wanted to be written
	* @retval	none
  */
void writeDigOutput(uint32_t portAdress, uint32_t pinSetting, uint32_t pinValues){

	
	pinSetting &= scan(GPIO_MODE_OUTPUT_PP,portAdress); //verifica se a porta da para escrever
	
	HAL_GPIO_WritePin((GPIO_TypeDef *)(portAdress*0x400+AHB1PERIPH_BASE), pinSetting&pinValues, GPIO_PIN_SET);
	HAL_GPIO_WritePin((GPIO_TypeDef *)(portAdress*0x400+AHB1PERIPH_BASE), pinSetting&(~pinValues), GPIO_PIN_RESET);
}




#endif






