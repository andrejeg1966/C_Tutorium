// MaxValueBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrderTraversal(TreeNode* node) {
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    printf("%d, ", node->data);
    inOrderTraversal(node->right);
}

TreeNode* maxValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

int main() {
    TreeNode* root = newTreeNode(13);
    root->left = newTreeNode(7);
    root->right = newTreeNode(15);

    root->left->left = newTreeNode(3);
    root->left->right = newTreeNode(8);

    root->right->left = newTreeNode(14);
    root->right->right = newTreeNode(19);

    root->right->right->left = newTreeNode(18);

    inOrderTraversal(root);
    printf("\n");

    TreeNode* minNode = maxValueNode(root);
    printf("Max value: %d\n", minNode->data);

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
