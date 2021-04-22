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
	int option;
	while( (option = getopt(argc, argv, "dh")) != -1){
		switch(option){
			case 'd':
				freopen("log.txt","w", stderr);
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

	return EXIT_SUCCESS;
}
