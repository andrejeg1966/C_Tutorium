// FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b) {
	return a + b;
}
void swap(int* a, int* b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
float add(int a, int b) {
	return a + b;
}

float subtract(int a, int b) {
	return a - b;
}

float multiply(int a, int b) {
	return a * b;
}

float divide(int a, int b) {
	return a / b;
}

int main() {

	int (*ptr)(int, int) = &addition;
	int x = 10, y = 20;
	int z = (*ptr)(x, y);

	printf("Addition of x: %d and y: %d = %d", x, y, z);

	printf("\n*****************************\n");
	
	void (*ptr1)(int*, int*) = &swap;

	int a = 10, b = 20;
	printf("Values of a: %d and b: %d before swap\n", a, b);

	(*ptr1)(&a, &b);
	printf("Values of a: %d and b: %d after swap", a, b);

	//Array of Function Pointers
	printf("\n*****************************\n");
	float (*ptr2[])(int, int) = { add, subtract, multiply, divide };

	int p = 15, q = 10;

	// 1 for addition, 2 for subtraction 
	// 3 for multiplication, 4 for division
	int op = 3;

	if (op > 5) return 0;
	printf("Result: %.2f", (*ptr2[op - 1])(p, q));

	//NULL Pointer
	printf("\n*****************************\n");
	int* ptr3 = (int*)malloc(sizeof(int));


	if (ptr3 == NULL) {
		printf("Memory Allocation Failed");
		exit(0);
	}
	else {
		printf("Memory Allocated successfully");
	}

	return 0;
}
