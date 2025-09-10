// Pointers to Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

struct book {
	char title[10];
	double price;
	int pages;
};

struct person {
	char name[10];
	int age;
	float weight;
};
int main() {

	struct book b1 = { "Learn C", 675.50, 325 };
	struct book* strptr;
	strptr = &b1;

	printf("Title: %s\n", strptr->title);
	printf("Price: %lf\n", strptr->price);
	printf("No of Pages: %d\n", strptr->pages);
	
	
	struct person person1 = { "Nixwe", 18, 50 };
	struct person* personPtr;
	personPtr = &person1;
	printf("Displaying the Data: \n");
	printf("Name: %s\n", personPtr->name);
	printf("Age: %d\n", personPtr->age);
	printf("Weight: %f", personPtr->weight);

	//strcpy_s(person1.name, 5, "Meena");
	person1.age = 20;
	person1.weight = 60;

	
	
	
	printf("Displaying the Data: \n");
	printf("Name: %s\n", personPtr->name);
	printf("Age: %d\n", personPtr->age);
	printf("Weight: %f", personPtr->weight);

	return 0;
}