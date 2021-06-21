#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "usart.h"
#include "gpio.h"
#include "adc.h"
#include "pwm.h"

static int automaticControl=1;

static const char* commandList[]=
	{
	//[basic gpio]			(0-7)
	"A",			//memory read
	"B",
	"C",
	"D",
	"E",
	"F"
	};

void getWord(char* command, uint8_t pos, char* word);
	
intmax_t getInt(char* command, uint8_t pos);

uint8_t numWords(char* command);

void parser(char* command, PWM_Bus motorVertical, PWM_Bus motorHorizontal);	

int control(void);
	
#endif
	
	
	
	


































