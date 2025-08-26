// DeleteNodeBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d, ", node->data);
    inOrderTraversal(node->right);
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* node, int data) {
    if (node == NULL) {
        return NULL;
    }

    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    }
    else {
        // Node with only one child or no child
        if (node->left == NULL) {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = minValueNode(node->right);

        // Copy the inorder successor's content to this node
        node->data = temp->data;

        // Delete the inorder successor
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

int main() {
    TreeNode* root = createNode(13);
    root->left = createNode(7);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(8);
    root->right->left = createNode(14);
    root->right->right = createNode(19);
    root->right->right->left = createNode(18
    );

    // Traverse
    inOrderTraversal(root);
    printf("\n"); // Creates a new line

    // Delete node 15
    root = deleteNode(root, 3);

    // Traverse
    inOrderTraversal(root);
    printf("\n");

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
