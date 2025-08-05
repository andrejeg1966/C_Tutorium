#include "arrayhw.h"
#include <cstdlib>
#include <iostream>
using namespace std;


void fillArray(int a[], int size)
{
	for (int i = 0; i < size; ++i)
		a[i] = rand();
}

void printArray(const int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << endl;
	}
}