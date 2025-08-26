// BinaryTreeArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>

#define ARRAY_SIZE 15  // Define the size of the array

char* get_data(char binaryTreeArray[], int index);
int left_child_index(int index);
int right_child_index(int index);

int main() {
    char binaryTreeArray[ARRAY_SIZE] = { 'R', 'A', 'B', 'C', 'D', 'E', 'F', '\0', '\0', '\0', '\0', '\0', '\0', 'G', '\0' };

    int rightChild = right_child_index(0);
    int leftChildOfRightChild = left_child_index(rightChild);
    char* data = get_data(binaryTreeArray, leftChildOfRightChild);

    if (data != NULL) {
        printf("root.right.left.data: %c\n", *data);
    }
    else {
        printf("No data found.\n");
    }

    return 0;
}

char* get_data(char binaryTreeArray[], int index) {
    if (index >= 0 && index < ARRAY_SIZE) {
        return &binaryTreeArray[index];
    }
    return NULL;
}

int left_child_index(int index) {
    return 2 * index + 1;
}

int right_child_index(int index) {
    return 2 * index + 2;
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
