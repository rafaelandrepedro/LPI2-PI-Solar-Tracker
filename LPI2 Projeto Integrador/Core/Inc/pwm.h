#ifndef PWM_H
#define PWM_H
#include "tim.h"
#include <stdlib.h>
typedef struct {
	TIM_HandleTypeDef * timHandle;
	uint32_t PWM_Pin;
}PWM_Port;

typedef struct {
	uint32_t GPIOx;
	uint32_t GPIO_Pin;
}GPIO_Port;

typedef struct {
	PWM_Port pwm_Port;
	GPIO_Port gpio_Port;
}PWM_Bus;



void PWMChannelConfig(PWM_Port port);
void PWMDutyCycle(PWM_Port port, uint8_t dutyCycle);
void PWMSignedDutyCycle(PWM_Bus bus, int8_t dutyCycle);
#endif
