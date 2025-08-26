// DeleteNodeinLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

Node* deleteSpecificNode(Node* head, Node* nodeToDelete) {
    if (head == nodeToDelete) {
        Node* newHead = head->next;
        free(head);
        return newHead;
    }

    Node* currentNode = head;
    while (currentNode->next && currentNode->next != nodeToDelete) {
        //Iterate up to previous node from node to be deleting,up to (nodeToDelete -1)
        currentNode = currentNode->next;
    }

    if (currentNode->next == NULL) {
        return head;
    }
    //get the node to be deletaed and save it
    Node* temp = currentNode->next;
    //(nodeToDelete -1) points to (nodeToDelete + 1)
    currentNode->next = currentNode->next->next;
    free(temp);

    return head;
}

int main() {
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    

    node1->data = 7;
    node2->data = 11;
    node3->data = 3;
    node4->data = 2;
    

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
   

    printf("Before deletion:\n");
    traverseAndPrint(node1);

    node1 = deleteSpecificNode(node1, node1);

    printf("\nAfter deletion:\n");
    traverseAndPrint(node1);

    free(node2);
    free(node3);
    free(node4);
   
    return 0;
}

//C
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
