#include "encoder.h"

//FOR MAIN
	/*
		Init for the encoder
		MUST be called each time an object is created/reseted
			encoder - encoder address
			CLK - pin A of the encoder (MUST be the same used in the EXTI)
			DT - pin B of the encoder
			steps - number of transitions/revolution
	*/
	void encoderInit(Encoder_t* encoder, GPIO_Port CLK, GPIO_Port DT, int steps){
		encoder->CLK=CLK;
		encoder->DT=DT;
		encoder->steps=steps;
		encoder->pos=0;
		encoder->lastRegistedPos=0;
		encoder->speed=0.0;
	}

//FOR EXTI
	/*
		Update of the position
		MUST be called every time the EXTI occurs (rise and falling edge)
			encoder - encoder address
	*/
	void updatePosition(Encoder_t* encoder){
		if(HAL_GPIO_ReadPin((GPIO_TypeDef *)(encoder->CLK.GPIOx), encoder->CLK.GPIO_Pin)==HAL_GPIO_ReadPin((GPIO_TypeDef *)(encoder->DT.GPIOx), encoder->CLK.GPIO_Pin))
			encoder->pos++;
		else
			encoder->pos--;
	}
	
//FOR TIM
	/*
		Update of the speed
		MUST be called every time the EXTI occurs (rise and falling edge)
			encoder - encoder address
	*/
	void updateSpeed(Encoder_t* encoder, float updateRate){
		encoder->speed=((float)(encoder->pos-encoder->lastRegistedPos)/(float)(encoder->steps))/(float)updateRate;
	}
	
//FOR ANYWHERE
	int readPosition(Encoder_t* encoder){
		int pos=encoder->pos;
		pos=pos%encoder->steps;
		if(pos<0)
			pos+=encoder->steps;
		return pos;
	}
	
	int readSpeed(Encoder_t* encoder){
		return encoder->speed;
	}



















