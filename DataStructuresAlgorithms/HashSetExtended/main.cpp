// HashSetExtended.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_COUNT 10
#define MAX_STRING_LENGTH 256 // Define a maximum string length

typedef struct Node {
    char value[MAX_STRING_LENGTH]; // Use a fixed-size array for values
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[BUCKET_COUNT];
} SimpleHashSet;

unsigned int hashFunction(const char* value) {
    unsigned int hash = 0;
    while (*value) {
        hash = (hash + *value++) % BUCKET_COUNT;
    }
    return hash;
}

void initHashSet(SimpleHashSet* set) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        set->buckets[i] = NULL;
    }
}

int contains(SimpleHashSet* set, const char* value) {
    unsigned int index = hashFunction(value);
    Node* node = set->buckets[index];
    while (node != NULL) {
        if (strcmp(node->value, value) == 0) {
            return 1; // Found
        }
        node = node->next;
    }
    return 0; // Not found
}

void removeValue(SimpleHashSet* set, const char* value) {
    unsigned int index = hashFunction(value);
    Node** node = &(set->buckets[index]);
    while (*node != NULL) {
        if (strcmp((*node)->value, value) == 0) {
            Node* toDelete = *node;
            *node = (*node)->next;
            free(toDelete); // Just free the node, not toDelete->value
            return; // Value removed
        }
        node = &((*node)->next);
    }
}

void add(SimpleHashSet* set, const char* value) {
    unsigned int index = hashFunction(value);

    // Check if the value already exists to avoid duplicates
    Node* current = set->buckets[index];
    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            // Value already exists, do not add again
            return;
        }
        current = current->next;
    }

    // Add new value
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return; // Handle malloc failure

    strncpy(newNode->value, value, MAX_STRING_LENGTH);
    newNode->value[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
}

void printHashSet(SimpleHashSet* set) {
    printf("Hash Set Contents:\n");
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Node* node = set->buckets[i];
        printf("Bucket %d: ", i);
        while (node) {
            printf("%s ", node->value);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    SimpleHashSet hashSet;
    initHashSet(&hashSet);

    add(&hashSet, "Charlotte");
    add(&hashSet, "Thomas");
    add(&hashSet, "Jens");
    add(&hashSet, "Peter");
    add(&hashSet, "Lisa");
    add(&hashSet, "Adele");
    add(&hashSet, "Michaela");
    add(&hashSet, "Bob");

    printHashSet(&hashSet);

    printf("\n'Peter' is in the set: %s\n", contains(&hashSet, "Peter") ? "true" : "false");
    printf("Removing 'Peter'\n");
    removeValue(&hashSet, "Peter");
    printf("'Peter' is in the set: %s\n", contains(&hashSet, "Peter") ? "true" : "false");
    printf("'Adele' has hash code: %u\n", hashFunction("Adele"));

    // Free memory, omitted for brevity
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
