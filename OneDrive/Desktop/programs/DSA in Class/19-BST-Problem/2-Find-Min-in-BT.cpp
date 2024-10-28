/*
Problem Statement



You find yourself in a mysterious binary forest where each tree node is associated with a treasure chest containing a certain number of gold coins. 



Your task is to navigate through the forest, construct a binary tree based on the clues you find, and determine the maximum amount of gold coins you can collect using preorder traversal.



Note: If multiple nodes (gold coins) in the tree have the same maximum value, your function should print the value of the first node encountered during the preorder traversal.

Input format :
The first line of input consists of an integer N, representing the number of treasure chests you discover in the forest.

The second line consists of N space-separated integers, each representing the number of gold coins in a treasure chest encountered in the order of your journey.

Output format :
The output prints a single integer, which represents the maximum amount of gold coins you can collect by navigating through the binary tree constructed from the given clues.

Sample test cases :
Input 1 :
7
10 5 15 3 8 12 18
Output 1 :
18
Input 2 :
6
10 5 20 8 15 20
Output 2 :
20
*/

// You are using GCC
#include <iostream>
#include <climits>
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
    
    //Type your code here
    if(root==NULL){
       root=createNode(data);
       return root;
   }
   if(data< root->data){
        root->left= insertNode(root->left, data);
   }
   else{
        root->right=insertNode(root->right, data);
   }
   return root;
    
}

//Function to find the maximum node in the preorder traversal
int  findMaxNodePreorder(struct Node* root) {
    
    if(root==NULL){
        return INT_MIN;
    }
    int maxi= root->data;
    int leftMax= findMaxNodePreorder(root->left);
    int rightMax= findMaxNodePreorder(root->right);
    
    if(maxi < leftMax){
        maxi=leftMax;
    }
    if (maxi< rightMax){
       return rightMax;
    }
    
    return maxi;
}

int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    cin >> data;
    root = insertNode(root, data);

    for (int i = 1; i < n; i++) {
        cin >> data;
        insertNode(root, data);
    }

    int maxVal = INT_MIN; 
    maxVal=findMaxNodePreorder(root);
    cout << maxVal << endl;

    return 0;
}