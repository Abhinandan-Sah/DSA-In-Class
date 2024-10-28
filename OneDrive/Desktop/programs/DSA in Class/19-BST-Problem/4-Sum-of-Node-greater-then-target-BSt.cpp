/*
Problem Statement:



Geetha is exploring the world of binary search trees (BSTs) and wants to create a program to find the sum of all nodes in a BST that are greater than a given target value.



She has implemented a program to accomplish this and needs a problem statement for her task.

Input format :
The first line of input consists of an integer, n, representing the number of nodes in the BST.

The second line of input consists of an integer, denoting the values to be inserted into the BST.

The last line of input consists of a single integer, target, which is the target value.

Output format :
The output displays a single integer, which is the sum of all nodes in the BST with values greater than the target value.



Refer to the sample output for the formatting specifications.

Code constraints :
The test cases will fall under the following constraints:



1 <= n <= 10

1 <= target <= 100

Sample test cases :
Input 1 :
7
10 20 40 4 60 70 3
60
Output 1 :
70
Input 2 :
5
10 3 10 50 60
4
Output 2 :
120
*/



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) 
{
    if(root==NULL){
        return create(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int sumGtr(Node* root, int value) 
{ 
    if(root==NULL){
        return 0;
    }
    
    int sum = 0;
    
    sum += sumGtr(root->left, value);
    
    // if(root->data > value){
        //this is for sum of all node
        sum += root->data;
    // }
    
    sum += sumGtr(root->right, value);
    
    return sum;
}

int main() {
    Node* root = nullptr;
    int n, data, target;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    cin >> target;

    int result = sumGtr(root, target);
    
    cout << result;

    return 0;
}
