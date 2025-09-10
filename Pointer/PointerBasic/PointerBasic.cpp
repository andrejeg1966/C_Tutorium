// PointerBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>      // for return values
using namespace std;

int main() {

	float var1 = 10.55;
	float* floatptr = &var1;

	printf("var1: %f \nAddress of var1: %p \n\n", var1, &var1);
	printf("floatptr: %p \nAddress of floatptr: %p \n\n", floatptr, &floatptr);
	printf("var1: %f \nValue at floatptr: %f", var1, *floatptr);
	printf("\n********************************************\n");

	//Pointer to pointer
	float var = 10.23;
	float* intptr = &var;
	float** ptrptr = &intptr;

	printf("var: %f \nAddress of var: %p \n\n", var, &var);
	printf("inttptr: %p \nAddress of inttptr: %p \n\n", intptr, &intptr);
	printf("var: %f \nValue at intptr: %f \n\n", var, *intptr);
	printf("\n********************************************\n");
	printf("ptrptr: %p \nAddress of ptrtptr: %p \n\n", ptrptr, &ptrptr);
	printf("intptr: %p \nValue at ptrptr: %p \n\n", intptr, *ptrptr);
	printf("var: %f \n*intptr: %d \n**ptrptr: %f", var, *intptr, **ptrptr);

	printf("\n********************************************\n");

	//Arrays and pointer
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* b = arr;

	printf("Address of a[0]: %x value at a[0] : %d\n", b, *b);

	b++;
	printf("Address of a[1]: %x value at a[1] : %d\n", b, *b);

	b++;
	printf("Address of a[2]: %x value at a[2] : %d\n", b, *b);

	b++;
	printf("Address of a[3]: %x value at a[3] : %d\n", b, *b);

	b++;
	printf("Address of a[4]: %x value at a[4] : %d\n", b, *b);

	printf("\n********************************************");
	//The malloc() Function
	char name[20];
    //name = (char *) malloc(strlen("TutorialsPoint"));
	strcpy_s(name, _countof(name), "TutorialsPoint");
   
   if(name == NULL) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      printf("\nName = %s\n", name );
   }


	return 0;
}