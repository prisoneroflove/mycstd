#include<stdio.h>

void assert(int condition, char* msg){
	if(condition){
		printf("Passed\n");
	}else{
		printf("\nFAILED : %s\n\n",msg );
	}
}
