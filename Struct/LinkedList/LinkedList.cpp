#include <stdio.h>
#include <stdlib.h>

struct mystruct {
    int a;
    struct mystruct* b;
};

int main() {

    struct mystruct* p1, * p2, * start;
    int i;

    p1 = (struct mystruct*)malloc(sizeof(struct mystruct));
    p1->a = 10; p1->b = NULL;

    start = p1;

    for (i = 1; i <= 3; i++) {
        p2 = (struct mystruct*)malloc(sizeof(struct mystruct));
        p2->a = i * 2;
        p2->b = NULL;
        p1->b = p2; //Der element next von vorherige struct zeigt auf naechste struct
        p1 = p2;    //die naechste strcuct adresse ist aktuell
    }

    p1 = start;
    while (p1 != NULL) {
        printf("Add of current: %d a: %d add of next: %d\n", p1, p1->a, p1->b);
        p1 = p1->b;
    }

    return 0;
}