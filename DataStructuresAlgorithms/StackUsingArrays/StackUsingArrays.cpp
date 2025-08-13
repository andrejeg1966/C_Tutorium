// StackUsingArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->stack = (int*)malloc(capacity * sizeof(int));
    newStack->top = -1;
    newStack->capacity = capacity;
    return newStack;
}

void push(Stack* s, int element) {
    if (s->top == s->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    s->stack[++s->top] = element;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top--];
}

int peek(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int size(Stack* s) {
    return s->top + 1;
}

void printStack(Stack* s) {
    printf("Stack: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%c ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    Stack* myStack = createStack(100);

    push(myStack, 'A');
    push(myStack, 'B');
    push(myStack, 'C');

    // Print initial stack
    printStack(myStack);
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", size(myStack));
    printf("Pop: %c\n", pop(myStack));
    printf("Peek: %c\n", peek(myStack));
    printf("isEmpty: %d\n", isEmpty(myStack));
    printf("Size: %d\n", size(myStack));

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
