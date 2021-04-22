#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "function.h"


int add(int first, int sec){
	return 0;
}
int multiply(int first, int sec){
	return 0;
}
int subtract(int first, int sec){
	return 0;
}
float divide(int first, int sec){
	return 0;
}
int modulus(int first, int sec){
	return 0;
}


int main(int argc, char** argv){
	FILE* log;
	int option;
	int dFlag = 0;
	
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


	if(dFlag == 1)
		fclose(log);	
	return EXIT_SUCCESS;
}
