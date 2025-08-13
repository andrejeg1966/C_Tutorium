// QueueImplementationLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int length;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->length = 0;
    return newQueue;
}

void enqueue(Queue* q, char element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        q->length++;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    q->length++;
}

char dequeue(Queue* q) {
    if (q->length == 0) {
        printf("Queue is empty\n");
        return ' ';
    }
    Node* temp = q->front;
    q->front = temp->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->length--;
    char dequeued = temp->data;
    free(temp);
    return dequeued;
}

char peek(Queue* q) {
    if (q->length == 0) {
        printf("Queue is empty\n");
        return ' ';
    }
    return q->front->data;
}

int isEmpty(Queue* q) {
    return q->length == 0;
}

int size(Queue* q) {
    return q->length;
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* myQueue = createQueue();

    enqueue(myQueue, 'A');
    enqueue(myQueue, 'B');
    enqueue(myQueue, 'C');
    enqueue(myQueue, 'D');
    
    printf("Queue: ");
    printQueue(myQueue);

    printf("Dequeue: %c\n", dequeue(myQueue));
    printf("Peek: %c\n", peek(myQueue));
    printf("isEmpty: %d\n", isEmpty(myQueue));
    printf("Size: %d\n", size(myQueue));

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
