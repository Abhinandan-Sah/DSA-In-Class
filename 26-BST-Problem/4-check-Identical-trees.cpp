/*
Problem Statement



Sara is an aspiring computer scientist working on a binary tree problem. Her task is to compare two binary trees to see if they are identical in structure and values. Can you assist her in solving this challenge?



To accomplish this, you need to develop a function that takes the roots of two binary trees as input and performs a preorder traversal on both trees simultaneously. 



During the traversal, you will compare the values of the corresponding nodes in both trees. If at any point the values differ, the trees are not identical, and the function should return false. However, if the traversal completes without finding any differences, the trees are considered identical, and the function should return true.

Input format :
The first line of input consists of an integer n1, followed by a list of space-separated integers representing the elements to be inserted into the first binary tree.

The third line consists of an integer n2, followed by a list of space-separated integers representing the elements to be inserted into the second binary tree.

Output format :
If the two binary trees are identical, the output prints, "The two binary trees are identical."

Otherwise, print "The two binary trees are not identical."

Sample test cases :
Input 1 :
5
10 5 15 2 8
5
10 5 15 2 8
Output 1 :
The two binary trees are identical.
Input 2 :
3
5 12 8
3
10 2 1
Output 2 :
The two binary trees are not identical.
Input 3 :
3
10 2 8
2
10 2
Output 3 :
The two binary trees are not identical.
*/

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = new struct Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to build the tree
struct Node* insertNode(struct Node* root, int data) {
    
    if(root==NULL){
        return createNode(data);
    }
    
    root->left= insertNode(root->left, data);
    root->right= insertNode(root->right, data);
    return root;
    
}

//Function to check if the trees are identical
bool isIdentical(struct Node* root1, struct Node* root2) {
    
    if( root1==NULL && root2==NULL){
        return true;
    }
    
    if(root1!=NULL && root2!=NULL){
        return 
            (
            (root1->data== root2->data)  &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right)
            );
    }
    
    return false;
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int n1, n2, data;

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> data;
        root1 = insertNode(root1, data);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> data;
        root2 = insertNode(root2, data);
    }

    if (isIdentical(root1, root2)) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }

    return 0;
}