/*
Problem Statement

John is learning about binary search trees (BST) in his computer science class. 

He is given the task of creating a program that inserts nodes into a BST and calculates its height. 

Create a program to help John with this task. The program should allow him to input the number of nodes in the BST and the data for each node. It should then calculate the height of the BST and output the result.

Input format :
The first line of input consists of an integer N, which represents the number of nodes in the BST.

The second line consists of N integers, representing the data for each node in the BST.

Output format :
The output prints a single integer, the height of the BST.

Code constraints :
The program should handle tree structures with a maximum of 1000 nodes.

Sample test cases :
Input 1 :
7
50 30 70 20 40 60 80
Output 1 :
3
Input 2 :
3
10 5 15
Output 2 :
2
*/



#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given data
struct TreeNode* newNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the height of a BST
int height(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    
    int left= height(root->left);
    int right= height(root->right);
    if(left> right){
        return left+1;
    }
    else{
        return right+1;
    }
    
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes, nodeData;
 
    scanf("%d", &numNodes);

    // Insert nodes into the BST
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &nodeData);
        root = insert(root, nodeData);
    }

    // Calculate the height of the BST
    int treeHeight = height(root);

    printf("%d", treeHeight);

    return 0;
}