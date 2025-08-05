#include <stdio.h>

struct mystruct {
	int a;
	struct mystruct* b;
};

int main() {

	struct mystruct x = { 10, NULL }, y = { 20, NULL }, z = { 30, NULL };
	struct mystruct* p1, * p2, * p3;

	p1 = &x;
	p2 = &y;
	p3 = &z;

	x.b = p2;
	y.b = p3;

	printf("Address of x: %lu a: %d Address of next: %lu\n", p1, x.a, x.b);
	printf("Address of y: %d a: %d Address of next: %d\n", p2, y.a, y.b);
	printf("Address of z: %d a: %d Address of next: %d\n", p3, z.a, z.b);

	return 0;
}