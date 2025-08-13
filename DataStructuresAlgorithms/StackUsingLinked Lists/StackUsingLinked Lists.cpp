// StackUsingLinked Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node* next;
};

struct Stack {
    struct Node* head;
    int size;
};

struct Stack* createStack() {
    struct Stack* s = (Stack*)malloc(sizeof(struct Stack));
    s->head = NULL;
    s->size = 0;
    return s;
}

void push(struct Stack* s, char value) {
    Node* newNode = (Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = s->head;
    //Head will be the next inserted node with new next and value 
    s->head = newNode;
    s->size++;
}

char pop(struct Stack* s) {
    if (s->size == 0) {
        return ' ';
    }
    struct Node* popped = s->head;
    s->head = s->head->next;
    char poppedValue = popped->value;
    free(popped);
    s->size--;
    return poppedValue;
}

char peek(struct Stack* s) {
    if (s->size == 0) {
        return ' ';
    }
    return s->head->value;
}

int isEmpty(struct Stack* s) {
    return s->size == 0;
}

int stackSize(struct Stack* s) {
    return s->size;
}

int main() {
    struct Stack* myStack = createStack();

    push(myStack, 'A');
    push(myStack, 'B');
    push(myStack, 'C');

    printf("Pop: %c\n", pop(myStack));
    printf("Peek: %c\n", peek(myStack));
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", stackSize(myStack));

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
