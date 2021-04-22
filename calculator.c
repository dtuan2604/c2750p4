#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

#define TEST 1

int add(int first, int sec){
	return first + sec;
}
int multiply(int first, int sec){
	return first * sec;
}
int subtract(int first, int sec){
	return first - sec;
}
float divide(int first, int sec){
	return (float)first/sec;
}
int modulus(int first, int sec){
	return first % sec;
}


int main(int argc, char** argv){
	FILE* log;
	int option;
	int dFlag = 0;
	char opr[9]; 
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
		printf("add\nmultiply\ndivide\nsubtract\nmodulus\n");
		scanf("%s", opr);
		while(strcmp(opr,"add") != 0 && strcmp(opr,"multiply") != 0 && strcmp(opr,"divide") != 0
			&& strcmp(opr,"subtract") != 0 && strcmp(opr,"modulus") != 0){
			fprintf(stderr, "Unknown operation '%s'\n",opr);
			printf("Please try again: ");
			scanf("%s", opr);
		} 
		printf("The operation is %s", opr);
		break;

	}

	if(dFlag == 1)
		fclose(log);	
	return EXIT_SUCCESS;
}
