#ifndef PWM_H
#define PWM_H
#include "tim.h"
#include "gpio.h"
#include <stdlib.h>

#define PIN_GND (GPIO_Port){0,0}

//Portos possiveis: portos roxos				https://os.mbed.com/platforms/ST-Nucleo-F767ZI/
//conjunto de timer + numero de PWM
typedef struct {
	TIM_HandleTypeDef * timHandle;
	uint32_t PWM_Pin;
}PWM_Port;

//conjunto de porto de PWM + porto de referência
typedef struct {
	PWM_Port pwm_Port;
	GPIO_Port gpio_Port;
}PWM_Bus;


/*
Configurar um porto para PWM
port->estrutura do porto de PWM
*/
void PWMChannelConfig(PWM_Port port);

/*
Alterar o dutycycle do PWM
port->estrutura do porto de PWM
port->valor de dutycycle [-100;100]
*/
void PWMDutyCycle(PWM_Bus port, int8_t dutyCycle);
#endif
