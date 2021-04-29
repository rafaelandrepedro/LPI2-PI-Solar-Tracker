#include "gpio.h"

#define RESET_POSITION

typedef struct {
	GPIO_Port CLK;
	GPIO_Port DT;
}Encoder_Bus;

typedef struct {
	int32_t pos;
	uint16_t steps;
}Encoder;

void moveStep(Encoder encoder){

}






	

	
	
