// PointerBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	float var1 = 10.55;
	float* floatptr = &var1;

	printf("var1: %f \nAddress of var1: %p \n\n", var1, &var1);
	printf("floatptr: %p \nAddress of floatptr: %p \n\n", floatptr, &floatptr);
	printf("var1: %f \nValue at floatptr: %f", var1, *floatptr);
	printf("\n********************************************");

	//Pointer to pointer
	int var = 10;
	int* intptr = &var;
	int** ptrptr = &intptr;

	printf("var: %d \nAddress of var: %d \n\n", var, &var);
	printf("inttptr: %d \nAddress of inttptr: %d \n\n", intptr, &intptr);
	printf("var: %d \nValue at intptr: %d \n\n", var, *intptr);
	printf("ptrptr: %d \nAddress of ptrtptr: %d \n\n", ptrptr, &ptrptr);
	printf("intptr: %d \nValue at ptrptr: %d \n\n", intptr, *ptrptr);
	printf("var: %d \n*intptr: %d \n**ptrptr: %d", var, *intptr, **ptrptr);

	printf("\n********************************************");

	//Arrays and pointer
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* b = arr;

	printf("Address of a[0]: %d value at a[0] : %d\n", b, *b);

	b++;
	printf("Address of a[1]: %d value at a[1] : %d\n", b, *b);

	b++;
	printf("Address of a[2]: %d value at a[2] : %d\n", b, *b);

	b++;
	printf("Address of a[3]: %d value at a[3] : %d\n", b, *b);

	b++;
	printf("Address of a[4]: %d value at a[4] : %d\n", b, *b);

	printf("\n********************************************");
	//The malloc() Function
	char *name;
    name = (char *) malloc(strlen("TutorialsPoint"));
	
   //strcpy(name, "TutorialsPoint");
   
   if(name == NULL) {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   } else {
      printf("Name = %s\n", name );
   }


	return 0;
}