#ifndef CONTROL_H
#define CONTROL_H
#define MIN(X, Y)(((X)<(Y))?(X):(Y))
#include "adc.h"
#include "pwm.h"
#include "encoder.h"

void proportionalControl(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight, PWM_Bus motorHorizontal, PWM_Bus motorVertical, uint16_t lowThreshold, uint16_t highThreshold, uint16_t maxThreshold);

void onOffControl(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight, PWM_Bus motorHorizontal, PWM_Bus motorVertical, int lowThreshold, int highThreshold);

void resetControl(Encoder_t encoder, PWM_Bus motorHorizontal, uint16_t lowThreshold);

uint16_t averageLight(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight);

#endif
