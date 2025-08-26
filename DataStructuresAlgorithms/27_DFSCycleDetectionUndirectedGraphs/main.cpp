// 27_DFSCycleDetectionUndirectedGraphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdbool.h>

#define SIZE 7

typedef struct {
    int adjMatrix[SIZE][SIZE];
    char vertexData[SIZE];
} Graph;

void initGraph(Graph* g) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            g->adjMatrix[i][j] = 0;
        }
        g->vertexData[i] = '\0';
    }
}

void addEdge(Graph* g, int u, int v) {
    if (u >= 0 && u < SIZE && v >= 0 && v < SIZE) {
        g->adjMatrix[u][v] = 1;
        g->adjMatrix[v][u] = 1;
    }
}

void addVertexData(Graph* g, int vertex, char data) {
    if (vertex >= 0 && vertex < SIZE) {
        g->vertexData[vertex] = data;
    }
}

void printGraph(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nVertex Data:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Vertex %d: %c\n", i, g->vertexData[i]);
    }
}

bool dfsUtil(Graph* g, int v, bool visited[], int parent) {
    visited[v] = true;

    for (int i = 0; i < SIZE; i++) {
        if (g->adjMatrix[v][i] == 1) {
            if (!visited[i]) {
                if (dfsUtil(g, i, visited, v)) {
                    return true;
                }
            }
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(Graph* g) {
    bool visited[SIZE] = { false };

    for (int i = 0; i < SIZE; i++) {
        if (!visited[i]) {
            if (dfsUtil(g, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    Graph g;
    initGraph(&g);

    addVertexData(&g, 0, 'A');
    addVertexData(&g, 1, 'B');
    addVertexData(&g, 2, 'C');
    addVertexData(&g, 3, 'D');
    addVertexData(&g, 4, 'E');
    addVertexData(&g, 5, 'F');
    addVertexData(&g, 6, 'G');

    addEdge(&g, 3, 0); // D - A
    addEdge(&g, 0, 2); // A - C
    addEdge(&g, 0, 3); // A - D
    addEdge(&g, 0, 4); // A - E
    addEdge(&g, 4, 2); // E - C
    addEdge(&g, 2, 5); // C - F
    addEdge(&g, 2, 1); // C - B
    addEdge(&g, 2, 6); // C - G
    addEdge(&g, 1, 5); // B - F

    printGraph(&g);

    printf("\nGraph has cycle: %s\n", isCyclic(&g) ? "Yes" : "No");
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
