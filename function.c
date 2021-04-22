#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
void help(){
	printf("The options for program are:\n");
	printf("-d: Turn off all error messages.\n");
	printf("-h: Display help menu.\n");
	printf("When running the program will ask you whether you would like to\n");
	printf("add, multiply, divide, subtract and modulus. After that, the program\n");
	printf("will prompt you to enter any two integer numbers to perform the operation.\n"); 
}


void testAdd(){
	int first = 26;
	int sec = 10;
	int expected = 36;
	int actual = add(first, sec);
	
	if(expected != actual){
		fprintf(stderr,"testAdd has failed! actual: %d, expected: %d", actual, expected);
		exit(1);
	}	
	return;
}
void testMultiply(){
 	int first = 26;
        int sec = 10;
        int expected = 260;
        int actual = multiply(first, sec);


	if(expected != actual){
        	fprintf(stderr,"testMultiply has failed! actual: %d, expected: %d", actual, expected);
                exit(1);
        }
        return;
}
void testDivide(){
        int first = 260;
        int sec = 10;
        float expected = 26;
        float actual = divide(first, sec);


        if(expected != actual){
                fprintf(stderr,"testDivide has failed! actual: %f, expected: %f", actual, expected);
                exit(1);
        }
        return;
}
void testSubtract(){
        int first = 26;
        int sec = 10;
        int expected = 16;
        int actual = subtract(first, sec);


        if(expected != actual){
                fprintf(stderr,"testSubtract has failed! actual: %d, expected: %d", actual, expected);
                exit(1);
        }
        return;
}
void testModulus(){
        int first = 26;
        int sec = 10;
        int expected = 16;
        int actual = modulus(first, sec);


        if(expected != actual){
                fprintf(stderr,"testModulus has failed! actual: %d, expected: %d", actual, expected);
                exit(1);
        }
        return;
}

void runTest(){
	testAdd();
	testMultiply();
	testDivide();
	testSubtract();
	testModulus();
}













































