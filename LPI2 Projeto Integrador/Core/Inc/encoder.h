#ifndef ENCODER_H
#define ENCODER_H
#include "gpio.h"
typedef struct {
	GPIO_Port CLK;
	GPIO_Port DT;
	int steps;
	//private:
	int pos;
	int lastRegistedPos;
	float speed;						//Hz
}Encoder_t;

//FOR MAIN
	/*
		Init for the encoder
		MUST be called each time an object is created/reseted
			encoder - encoder address
			CLK - pin A of the encoder (MUST be the same used in the EXTI)
			DT - pin B of the encoder
			steps - number of transitions/revolution
	*/
	void encoderInit(Encoder_t* encoder, GPIO_Port CLK, GPIO_Port DT, int steps);

//FOR EXTI
	/*
		Update of the position
		MUST be called every time the EXTI occurs (rise and falling edge)
			encoder - encoder address
	*/
	void updatePosition(Encoder_t* encoder);
	
//FOR TIM
	/*
		Update of the speed
		MUST be called every time the EXTI occurs (rise and falling edge)
			encoder - encoder address
	*/
	void updateSpeed(Encoder_t* encoder, float updateRate);
	
//FOR ANYWHERE
	int readPosition(Encoder_t* encoder);
	int readSpeed(Encoder_t* encoder);
#endif
