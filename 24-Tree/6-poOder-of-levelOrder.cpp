/*
Problem Statement

﻿

Venugopal is studying data structures and wants to build a program that can create a binary tree from a list of integers and then perform a postorder traversal on the constructed tree.



Create a Binary Tree: Venugopal can provide a list of integers to create a binary tree.
Perform Postorder Traversal: Venugopal can perform a postorder traversal on the constructed binary tree.
Input format :
The first line contains an integer n, denoting the number of integers in the list.

The second line contains 'n' space-separated integers representing the elements of the list.

Output format :
The output displays a single line containing space-separated integers representing the postorder traversal of the binary tree.



Refer to the sample output for formatting specifications.

Code constraints :
1 <= n <= 20

1 <= elements <= 1000

Sample test cases :
Input 1 :
5
1 3 4 5 2
Output 1 :
5 2 3 4 1 
Input 2 :
5
1 7 9 5 6
Output 2 :
5 6 7 9 1 
*/

// You are using GCC
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n)
{
    if(i<n){
        struct Node* temp= newNode(arr[i]);
        root=temp;
        
        root->left= insertLevelOrder(arr, root->left, 2*i +1, n);
        root->right=insertLevelOrder(arr, root->right, 2*i+2, n);
    }
    return root;
}

void postorderTraversal(struct Node* root) 
{
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}

int main() {
    int n, i;
    cin >> n;
    if(n<=0 && n>20 ){
        return 0;
    }
    int* arr = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    struct Node* root = insertLevelOrder(arr, NULL, 0, n);
    postorderTraversal(root);

    free(arr); 
    return 0;
}
