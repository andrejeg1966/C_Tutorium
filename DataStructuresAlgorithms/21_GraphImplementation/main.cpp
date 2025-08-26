// 21_GraphImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
void printAdjacencyMatrix(int matrix[4][4], int size) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printConnections(int matrix[4][4], char vertices[4], int size) {
    printf("\nConnections for each vertex:\n");
    for (int i = 0; i < size; i++) {
        printf("%c: ", vertices[i]);
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {  // if there is a connection
                printf("%c ", vertices[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char vertexData[4] = { 'A', 'B', 'C', 'D' };
    int adjacencyMatrix[4][4] = {
        {0, 1, 1, 1}, // Edges for A
        {1, 0, 1, 0}, // Edges for B
        {1, 1, 0, 0}, // Edges for C
        {1, 0, 0, 0}  // Edges for D
    };

    printAdjacencyMatrix(adjacencyMatrix, 4);
    printConnections(adjacencyMatrix, vertexData, 4);

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
