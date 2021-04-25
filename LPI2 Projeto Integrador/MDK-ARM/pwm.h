#ifndef PWM_H
#define PWM_H
#include "tim.h"
typedef struct {
	TIM_HandleTypeDef * timHandle;
	uint32_t PWM_Pin;
}PWM_Port;
#endif
