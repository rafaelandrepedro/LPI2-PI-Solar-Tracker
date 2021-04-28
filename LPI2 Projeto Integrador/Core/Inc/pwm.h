#ifndef PWM_H
#define PWM_H
#include "tim.h"
#include "gpio.h"
#include <stdlib.h>

#define PIN_GND (GPIO_Port){0,0}

typedef struct {
	TIM_HandleTypeDef * timHandle;
	uint32_t PWM_Pin;
}PWM_Port;

typedef struct {
	PWM_Port pwm_Port;
	GPIO_Port gpio_Port;
}PWM_Bus;



void PWMChannelConfig(PWM_Port port);
void PWMDutyCycle(PWM_Bus port, int8_t dutyCycle);
#endif
