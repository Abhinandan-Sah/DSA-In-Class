/*
Problem Statement



Rohith is a computer science student who is fascinated by data structures and algorithms. He recently learned about binary search trees and their traversal techniques. He wants to implement a program to create a binary search tree and perform post-order traversal on it, along with calculating the height of the tree.



Note:

The height of the tree is computed by finding the maximum height between the left and right subtrees of the root node and then adding 1 to that maximum height.

Input format :
The first line contains an integer, n, representing the number of elements to be inserted into the binary search tree.

The second line contains n space-separated integers, each representing an element to be inserted into the binary search tree.

Output format :
The first line should display the post-order traversal of the binary search tree, with elements separated by spaces.

The second line should display the height of the binary search tree.



Refer to the sample output for formatting specifications.

Code constraints :
1 <= n <= 20

1 <= elements <= 1000

Sample test cases :
Input 1 :
7
22 12 30 8 20 25 40
Output 1 :
Post-order traversal: 8 20 12 25 40 30 22 
Height of the tree: 2
*/

// You are using GCC
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

void postOrder(Node* root)
{
    if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    }
}

int getHeight(Node* root) 
{
   if(root==NULL){
       return -1;
   }
   
   return max(getHeight(root->left), getHeight(root->right)) +1;
}

int main() {
    Node* root = nullptr;

    int n;
    int data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << "\nHeight of the tree: " << getHeight(root) << endl;

    return 0;
}
