#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "function.h"

#define TEST 1

float add(float first, float sec){
	return first + sec;
}
float multiply(float first, float sec){
	return first * sec;
}
float subtract(float first, float sec){
	return first - sec;
}
float divide(float first, float sec){
	return first/sec;
}
float modulus(float first, float sec){
	return fmod(first,sec);
}
bool isNum(char* str){
	int size = (int)strlen(str);
	int i=0, dotFlag = 0;
	if(str[i] == '-' || isdigit(str[i]))
		i++;
	while(i<size){
		if(isdigit(str[i]) == false){
			if(str[i] == '.' && dotFlag < 1)
				dotFlag++;
			else{
				fprintf(stderr,"'%s' is not a number.\n",str);
				return false;
			}
		}
		i++;
	}

	return true;

}
float handleCal(char* first, char* sec, char* opr){
	float a = atof(first);
	float b = atof(sec);
	if(strcmp(opr,"add"))
		return add(a,b);
	else if(strcmp(opr,"multiply"))
		return multiply(a,b);
	else if(strcmp(opr,"subtract"))
		return subtract(a,b);
	else if(strcmp(opr,"divide"))
		return divide(a,b);
	else if(strcmp(opr,"modulus"))
		return modulus(a,b);
	else
		printf("Your calculator currently has problems.\n");
	return 0;
}

int main(int argc, char** argv){
	FILE* log;
	int option;
	int dFlag = 0;
//	float result; 
	char opr[9];
	char first[10], sec[10]; 
	bool yorn = true;
		
	while( (option = getopt(argc, argv, "dh")) != -1){
		switch(option){
			case 'd':
				log = freopen("log.txt","w", stderr);
				dFlag = 1;
				break;
			case 'h': 
				help();
				return 1;
			case '?':
				if( isprint(optopt))
					fprintf(stderr, "Unknow option `-%c`.\n",optopt);
				return EXIT_FAILURE;
			default:
				help();
				return 1;
		}
	
	}
	
	if(TEST){
		runTest();
	}	
		
	while(yorn){
		printf("Please enter operation you would like to perform with calculator:\n");
		printf("add\nmultiply\ndivide\nsubtract\nmodulus\nquit\n");
		scanf("%s", opr);
		while(strcmp(opr,"add") != 0 && strcmp(opr,"multiply") != 0 && strcmp(opr,"divide") != 0
			&& strcmp(opr,"subtract") != 0 && strcmp(opr,"modulus") != 0 && strcmp(opr, "quit")){
			fprintf(stderr, "Unknown operation '%s'\n",opr);
			printf("Please try again: ");
			scanf("%s", opr);
		} 
		printf("Please enter the two numbers separated by white space: ");
		scanf("%s", first);
		scanf("%s", sec);				
		while(!isNum(first) || !isNum(sec)){
			printf("Please try again: ");
			scanf("%s", first);
			scanf("%s", sec);
		}
		break;		
	}

	if(dFlag == 1)
		fclose(log);	
	return EXIT_SUCCESS;
}
