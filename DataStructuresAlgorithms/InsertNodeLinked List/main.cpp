// InsertNodeLinked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void traverseAndPrint(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("null\n");
}

Node* insertNodeAtPosition(Node* head, Node* newNode, int position) {
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* currentNode = head;
    for (int i = 1; i < position - 1 && currentNode != NULL; i++) {
        //Iterate up to previous node from node to be inserting,up to (nodeToInserte -1)
        currentNode = currentNode->next;
    }

    if (currentNode != NULL) {
        //New node points to the (nodeToInserte + 1)
        newNode->next = currentNode->next;
        //current node points the new node
        currentNode->next = newNode;
    }
    return head;
}

int main() {
    Node* node1 = (Node*) malloc(sizeof(Node));
    node1->data = 7;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->data = 3;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->data = 2;

    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->data = 9;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("Original list:\n");
    traverseAndPrint(node1);

    // Insert a new node with value 97 at position 2
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = 97;
    newNode->next = NULL;
    node1 = insertNodeAtPosition(node1, newNode, 5);

    printf("\nAfter insertion:\n");
    traverseAndPrint(node1);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(newNode);

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
