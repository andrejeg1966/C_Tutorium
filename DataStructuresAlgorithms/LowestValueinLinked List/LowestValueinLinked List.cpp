// LowestValueinLinked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findLowestValue(struct Node* head) {
    int minValue = head->data;
    struct Node* currentNode = head->next;
    while (currentNode) {
        if (currentNode->data < minValue) {
            minValue = currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return minValue;
}

int main() {
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 7;
    node2->data = 11;
    node3->data = 3;
    node4->data = 2;
    node5->data = 9;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    printf("The lowest value in the linked list is: %d\n", findLowestValue(node1));

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
