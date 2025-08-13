// HashSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SET_SIZE 10

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

Node* myHashSet[HASH_SET_SIZE] = { NULL };

int hashFunction(const char* value) {
    int sum = 0;
    for (int i = 0; value[i] != '\0'; i++) {
        sum += value[i];
    }
    return sum % HASH_SET_SIZE;
}

void add(const char* value) {
    int index = hashFunction(value);
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Manually allocate memory and copy the string
    newNode->value = (char*)malloc(strlen(value) + 1); // +1 for the null terminator
    strcpy(newNode->value, value);
    //strcpy_s(newNode->value,sizeof(newNode->value), value);
   

    newNode->next = NULL;

    if (myHashSet[index] == NULL) {
        myHashSet[index] = newNode;
    }
    else {
        Node* current = myHashSet[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int contains(const char* value) {
    int index = hashFunction(value);
    Node* current = myHashSet[index];
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return 1; // True
        }
        current = current->next;
    }
    return 0; // False
}

void freeHashSet() {
    for (int i = 0; i < HASH_SET_SIZE; i++) {
        Node* current = myHashSet[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->value); // Free the manually allocated string memory
            free(temp);
        }
    }
}

int main() {
    add("Jones");
    add("Lisa");
    add("Bob");
    add("Siri");
    add("Pete");
    add("Stuart");
    add("Goran");

    for (int i = 0; i < HASH_SET_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = myHashSet[i];
        while (current != NULL) {
            printf("%s -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }

    printf("\nContains Stuart: %s\n", contains("Stuart") ? "true" : "false");

    freeHashSet(); // Cleanup allocated memory

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
