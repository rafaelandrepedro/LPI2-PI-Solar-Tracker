#include "control.h"

void proportionalControl(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight, PWM_Bus motorHorizontal, PWM_Bus motorVertical, uint16_t lowThreshold, uint16_t highThreshold, uint16_t maxThreshold){
	
	uint16_t velocidade;

	while(analogRead(sensorUp) - analogRead(sensorDown)>lowThreshold){
		velocidade=MIN(abs(analogRead(sensorUp) - analogRead(sensorDown)),maxThreshold)*(100/maxThreshold);
		PWMDutyCycle(motorVertical,-velocidade);
	}

	while(analogRead(sensorUp) - analogRead(sensorDown)<lowThreshold){
		velocidade=MIN(abs(analogRead(sensorUp) - analogRead(sensorDown)),maxThreshold)*(100/maxThreshold);
		PWMDutyCycle(motorVertical,velocidade);
	}

	while(analogRead(sensorLeft) - analogRead(sensorRight)>lowThreshold){
		velocidade=MIN(abs(analogRead(sensorLeft) - analogRead(sensorRight)),maxThreshold)*(100/maxThreshold);
		PWMDutyCycle(motorHorizontal,-velocidade);
	}

	while(analogRead(sensorLeft) - analogRead(sensorRight)<lowThreshold){
		velocidade=MIN(abs(analogRead(sensorLeft) - analogRead(sensorRight)),maxThreshold)*(100/maxThreshold);
		PWMDutyCycle(motorHorizontal,velocidade);
	}
	
	PWMDutyCycle(motorVertical,0);
	PWMDutyCycle(motorHorizontal,0);
	
}

void onOffControl(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight, PWM_Bus motorHorizontal, PWM_Bus motorVertical, int lowThreshold, int highThreshold){

	int valor[6];
	valor[0]=analogRead(sensorUp);
	valor[1]=analogRead(sensorDown);
	valor[2]=analogRead(sensorLeft);
	valor[3]=analogRead(sensorRight);
	valor[4]=valor[0]-valor[1];
	valor[5]=valor[2]-valor[3];

	
	while((int)analogRead(sensorUp) - (int)analogRead(sensorDown)-350>lowThreshold){
		PWMDutyCycle(motorVertical,-100);
	}
	
	while((int)analogRead(sensorUp) - (int)analogRead(sensorDown)-350<-lowThreshold){
		PWMDutyCycle(motorVertical,100);
	}
	
	while((int)analogRead(sensorLeft) - (int)analogRead(sensorRight)>lowThreshold){
		PWMDutyCycle(motorHorizontal,-100);
	}
	
	while((int)analogRead(sensorLeft) - (int)analogRead(sensorRight)<-lowThreshold){
		PWMDutyCycle(motorHorizontal,100);
	}
	
	  PWMDutyCycle(motorVertical,0);
	  PWMDutyCycle(motorHorizontal,0);


	
}

void resetControl(Encoder_t encoder, PWM_Bus motorHorizontal, uint16_t lowThreshold){
			
	while(readPosition(&encoder)>lowThreshold){
		PWMDutyCycle(motorHorizontal,-100);
	}
	
	while(readPosition(&encoder)<-lowThreshold){
		PWMDutyCycle(motorHorizontal,100);
	}
	
	PWMDutyCycle(motorHorizontal,0);
}

uint16_t averageLight(ADC_Port sensorUp, ADC_Port sensorDown, ADC_Port sensorLeft, ADC_Port sensorRight){
	return (analogRead(sensorUp)+analogRead(sensorDown)+analogRead(sensorLeft)+analogRead(sensorRight))/4;
}

void move(PWM_Bus motorHorizontal, uint8_t speed){
	PWMDutyCycle(motorHorizontal,speed);
	HAL_Delay(500);
	PWMDutyCycle(motorHorizontal,0);
}
