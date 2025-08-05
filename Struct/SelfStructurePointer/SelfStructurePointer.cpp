#include <stdio.h>
#include <stdlib.h>


struct mystruct {
	int a;
	struct mystruct* b;
};

int main() {

	struct mystruct* p1, * p2, * p3;

	p1 = (struct mystruct*)malloc(sizeof(struct mystruct));
	p2 = (struct mystruct*)malloc(sizeof(struct mystruct));
	p3 = (struct mystruct*)malloc(sizeof(struct mystruct));

	p1->a = 10; p1->b = NULL;
	p2->a = 20; p2->b = NULL;
	p3->a = 30; p3->b = NULL;

	p1->b = p2;
	p2->b = p3;
	/*
	printf("Add of x: %d a: %d add of next: %d\n", p1, p1->a, p1->b);
	printf("add of y: %d a: %d add of next: %d\n", p2, p2->a, p2->b);
	printf("add of z: %d a: %d add of next: %d\n", p3, p3->a, p3->b);
	*/
	

	while (p1 != NULL) {
		printf("Add of current: %d a: %d add of next: %d\n", p1, p1->a, p1->b);
		p1 = p1->b;
	}

	return 0;
}