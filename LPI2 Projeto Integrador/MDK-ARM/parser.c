#include "parser.h"
intmax_t stringToInt(char* texto){
	intmax_t num=0;
	char* ch;
	if(texto[1]=='x'){
		ch=&texto[2];
		while(*ch!='\0'){
			num*=16;
			if(*ch>='0'&&*ch<='9')
				num+=(*ch)-'0';
			else if(*ch>='A'&&*ch<='F')
				num+=(*ch)-'A'+10;
			else break;
			ch++;
		}
	}
	else{
		if(texto[0]=='-'){
			ch=&texto[1];
			while(*ch!='\0'){
				num*=10;
				if(*ch>='0'&&*ch<='9')
					num+=(*ch)-'0';
				else break;
				ch++;
			}
			num*=-1;
		}
		else{
			ch=&texto[0];
			while(*ch!='\0'){
				num*=10;
				if(*ch>='0'&&*ch<='9')
					num+=(*ch)-'0';
				else break;
				ch++;
			}
		}
	}
	return num;
}

/**
  * @brief  Extracts a "word" string from a "phrase" string
  * @param	command		command string
  * @param	pos				word position on the string (starting on 0)
	* @param	word			return string array
	* @retval	none
  */
void getWord(char* command, uint8_t pos, char* word){
	char* ch=&(command[0]);
	while(pos!=0){
		while(*ch!=' '){
			if(*ch==(char)13){
				word[0]='\0';
				return;
			}
			ch++;
		}
		ch++;
		pos--;
	}
	uint8_t i=0;
	while(*ch!=' '&&*ch!=(char)13){
		word[i]=*ch;
		i++;
		ch++;
	}
	word[i]='\0';
	return;
}

intmax_t getInt(char* command, uint8_t pos){
	char text[16];
	getWord(command, 1, text);
	return stringToInt(text);
}

/**
  * @brief  Counts the number of words of the string
  * @param	command		command string
	* @retval	number of words present in the string
  */
uint8_t numWords(char* command){
	uint8_t pos=0;
	char* ch=&(command[0]);
	while(1){
		while(*ch!=' '){
			if(*ch==(char)13){
				return pos+1;
			}
			ch++;
		}
		ch++;
		pos++;
	}
}



/**
  * @brief  Searches and executes commands from the "commandList"
  * @param	command		command string
	* @retval	none
  */
void parser(char* command, PWM_Bus motorVertical, PWM_Bus motorHorizontal){
	char word[128];
	getWord(command, 0, word);

	
		//ON
	if(!strcmp(commandList[0],word)){
		automaticControl=1;
}
	
		//OFF
	else if(!strcmp(commandList[1],word)){
		automaticControl=0;
}
	
		//UP
	else if(!strcmp(commandList[2],word)){
		PWMDutyCycle(motorVertical,100);
		HAL_Delay(500);
		PWMDutyCycle(motorVertical,0);
	}
	
		//LEFT
	else if(!strcmp(commandList[3],word)){
		PWMDutyCycle(motorHorizontal,-100);
		HAL_Delay(500);
		PWMDutyCycle(motorHorizontal,0);
	}
	
		//RIGHT
	else if(!strcmp(commandList[4],word)){
		PWMDutyCycle(motorHorizontal,100);
		HAL_Delay(500);
		PWMDutyCycle(motorHorizontal,0);
	}
	
		//DOWN
	else if(!strcmp(commandList[5],word)){
		PWMDutyCycle(motorVertical,-100);
		HAL_Delay(500);
		PWMDutyCycle(motorVertical,0);
	}

}

int control(void){
	return automaticControl;
}
