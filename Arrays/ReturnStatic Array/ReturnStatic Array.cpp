// ReturnStatic Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>
int* arrfunction(int);
int main() {
	int x = 4, i;
	int* arr = arrfunction(x);
	printf("Square of %d: %f\n", x, *arr);
	printf("cube of %d: %f\n", x, arr[1]);
	printf("Square root of %d: %f\n", x, arr[2]);
	return 0;
}
int* arrfunction(int x) {
	static int arr_1[3];
	arr_1[0] = pow(x, 2);
	arr_1[1] = pow(x, 3);
	arr_1[2] = pow(x, 0.5);
	return arr_1;
}

/*
 Instead of passing an empty array from main(), we can declare an array inside the called function itself, fill it with the required values, and return its pointer.
 However, returning a pointer of a local variable is not acceptable, 
 as it points to a variable that no longer exists.
 Note that a local variable ceases to exist as soon as the scope of the function is over.Hence, we need to use a static array inside the called function(arrfunction)
and return its pointer back to main().

*/
