// QueueImplementationArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 10

struct Queue {
    int queue[CAPACITY];
    int front;
    int size;
};

void enqueue(struct Queue* q, int element);
int dequeue(struct Queue* q);
int peek(struct Queue* q);
bool isEmpty(struct Queue* q);
int size(struct Queue* q);
void printQueue(struct Queue* q);

int main() {
    struct Queue myQueue = { myQueue.front = 0, myQueue.size = 0 };

    enqueue(&myQueue, 'A');
    enqueue(&myQueue, 'B');
    enqueue(&myQueue, 'C');
    enqueue(&myQueue, 'D');

    printQueue(&myQueue);

    printf("Dequeue: %c\n", dequeue(&myQueue));
    printf("Peek: %c\n", peek(&myQueue));
    printf("isEmpty: %d\n", isEmpty(&myQueue));
    printf("Size: %d\n", size(&myQueue));

    return 0;
}

void enqueue(struct Queue* q, int element) {
    if (q->size == CAPACITY) {
        printf("Queue is full\n");
        return;
    }
    q->queue[(q->front + q->size) % CAPACITY] = element;
    q->size++;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->queue[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return item;
}

int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[q->front];
}

bool isEmpty(struct Queue* q) {
    return q->size == 0;
}

int size(struct Queue* q) {
    return q->size;
}

void printQueue(struct Queue* q) {
    printf("Queue: ");
    for (int i = 0; i < q->size; ++i) {
        printf("%c ", q->queue[(q->front + i) % CAPACITY]);
    }
    printf("\n");
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
