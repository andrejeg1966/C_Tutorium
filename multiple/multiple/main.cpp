#include "arrayhw.h"

int main(void)
{
	const int ARRAY_SIZE = 10;
	int myArray[ARRAY_SIZE];

	fillArray(myArray, ARRAY_SIZE);
	printArray(myArray, ARRAY_SIZE);
	return 0;
}