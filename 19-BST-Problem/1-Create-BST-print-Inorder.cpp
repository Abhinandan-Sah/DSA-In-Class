/*
Problem Statement



Dev is learning about binary trees and their traversals. He is particularly interested in the in-order traversal of a binary tree. 



He decides to write a program to perform an in-order traversal of a binary tree.



Write a program to help Dev that takes as input a set of integers and constructs a binary tree. Then, perform an in-order traversal of the tree and print the values of the nodes.

Input format :
The first line of input consists of an integer N, representing the number of nodes in the binary tree.

The second line consists of N integers, representing the values of the nodes in the tree.

Output format :
The output prints the in-order traversal of the tree.

Sample test cases :
Input 1 :
4 
17 23 65 24
Output 1 :
17 23 24 65 
Input 2 :
6
78 22 30 12 34 27
Output 2 :
12 22 27 30 34 78 
*/

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode= new Node();
    if(!newNode){
        cout<<"Memory Error";
        return NULL;
    }
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
    
}

//Function to build the tree
struct Node* insertNode(struct Node* root, int data) {
    if(root==NULL){
        root=createNode(data);
        return root;
    }
     if(data < root->data){
         root->left= insertNode(root->left, data);
     }
     else{
         root->right= insertNode(root->right, data);
     }
    return root;
}

//Function to perform the inorder traversal
void inorderTraversal(struct Node* root) {
    if(root!=NULL){
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }
    inorderTraversal(root);
    return 0;
}