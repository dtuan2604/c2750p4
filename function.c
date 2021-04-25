#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
void help(){
	printf("The options for program are:\n");
	printf("-d: Turn off all error messages.\n");
	printf("-h: Display help menu.\n");
	printf("When running the program will ask you whether you would like to\n");
	printf("add, multiply, divide, subtract and modulus. After that, the program\n");
	printf("will prompt you to enter any two numbers to perform the operation.\n"); 
}


void testAdd(){
	float first = 26;
	float sec = 10;
	float expected = 36;
	float actual = add(first, sec);
	
	if(expected != actual){
		fprintf(stderr,"testAdd has failed! actual: %f, expected: %f", actual, expected);
		exit(1);
	}	
	return;
}
void testMultiply(){
 	float first = 26;
        float sec = 10;
        float expected = 260;
        float actual = multiply(first, sec);


	if(expected != actual){
        	fprintf(stderr,"testMultiply has failed! actual: %f, expected: %f", actual, expected);
                exit(1);
        }
        return;
}
void testDivide(){
        float first = 260;
        float sec = 10;
        float expected = 26;
        float actual = divide(first, sec);


        if(expected != actual){
                fprintf(stderr,"testDivide has failed! actual: %f, expected: %f", actual, expected);
                exit(1);
        }
        return;
}
void testSubtract(){
        float first = 26;
        float sec = 10;
        float expected = 16;
        float actual = subtract(first, sec);


        if(expected != actual){
                fprintf(stderr,"testSubtract has failed! actual: %f, expected: %f", actual, expected);
                exit(1);
        }
        return;
}
void testModulus(){
        float first = 26;
        float sec = 10;
        float expected = 6;
        float actual = modulus(first, sec);


        if(expected != actual){
                fprintf(stderr,"testModulus has failed! actual: %f, expected: %f", actual, expected);
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













































