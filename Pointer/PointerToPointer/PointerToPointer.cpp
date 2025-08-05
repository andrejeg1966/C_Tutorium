#include <stdio.h>
#include <stdlib.h>
struct element
{
	int value;            /* der Wert des Elements          */
	struct element* next; /* Zeiger auf das nächste Element */
};
void append(struct element** lst, int value)
{
	lst = &(*lst)->next;
	printf("\n*******************");
	
	printf("\n*******************");
}
int main() {

	int a = 10;
	int* b = &a;
	printf("a: %d \nAddress of 'a': %d \nValue at a: %d\n\n", a, b, *b);

	int** c = &b;
	printf("b: %d \nPointer to 'b' is c: %d \nValue at b: %d\n", b, c, *c);
	printf("Value of 'a' from 'c': %d", **c);

	struct element* Liste;
	//Liste = (struct element *) malloc(sizeof(struct element)); 
	//Liste->value = 2;
	//Liste->next = NULL;
	Liste = NULL;
	append(&Liste, 1);
	

	return 0;
}