#ifndef _PARSER_H
#define _PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "usart.h"
#include "gpio.h"
#include "adc.h"

static const char* commandList[]=
	{
	//[basic gpio]			(0-7)
	"ON",			//memory read
	"OFF",
	"UP",
	"LEFT",
	"RIGHT",
	"DOWN"
	};

void getWord(char* command, uint8_t pos, char* word);
	
intmax_t getInt(char* command, uint8_t pos);

uint8_t numWords(char* command);

void parser(char* command);	

	
	
#endif
	
	
	
	


































