// ArraysOfPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 3;

typedef struct {
    char title[50];
    float price;
} Book;

int main() {

    int var[] = { 10, 100, 200 };
    int i, * ptr[MAX];

    for (i = 0; i < MAX; i++) {
        ptr[i] = &var[i]; /* assign the address of integer. */
    }

    for (i = 0; i < MAX; i++) {
        printf("Value of var[%d] = %d\n", i, *ptr[i]);
    }

    printf("\n*******************************");

    
    return 0;
}
