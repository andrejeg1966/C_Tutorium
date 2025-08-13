// Circular Singly Linked.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));

    node1->data = 13;
    node2->data = 51;
    node3->data = 113;
    node4->data = 21;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;  // Circular link

    Node* currentNode = node1;
    Node* startNode = node1;
    printf("%d -> ", currentNode->data);
    currentNode = currentNode->next;

    while (currentNode != startNode) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("...\n");  // Indicating the list loops back

    free(node1);
    free(node2);
    free(node3);
    free(node4);

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
