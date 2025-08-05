// Preprocessors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int display();
#pragma startup display
#pragma exit display

#define tokenpaster(n) printf ("token" #n " = %d", token##n)
#define  message_for(a, b)  \
   printf(#a " and " #b ": We love you!\n")

int main() {
	int token34 = 40;
	printf("\nI am in main function");
	printf("\n");
	tokenpaster(34);
	printf("\n");
	message_for(Carole, Debra);
	return 0;
}
int display() {
	printf("\nI am in display function");
	return 0;
}

