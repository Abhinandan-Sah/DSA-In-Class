/*
Problem Statement



You are given a binary tree, and your task is to determine whether the tree contains any duplicate values or not.	

Input format :
The first line of input consists of an integer representing the value of the root node.

For each node in the tree, there are two integers,

Left child data: an integer representing the value of the left child node. Use -1 to indicate no left child.

Right child data: an integer representing the value of the right child node. Use -1 to indicate no right child.

Output format :
Print "Yes" if the binary tree contains duplicate values.

Else, print "No".

Sample test cases :
Input 1 :
1
2
3
-1
2
-1
-1
-1
-1
Output 1 :
Yes
Input 2 :
1
20
3
-1
4
-1
-1
-1
-1
Output 2 :
No
*/

#include <iostream>
#include <unordered_set>

using namespace std;

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to build a binary tree
Node* buildBinaryTree() {
    int data;
    cin >> data;

    if (data == -1) {
        return nullptr; 
    }

    Node* root = createNode(data);

    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

// Helper function to check if a binary tree has duplicate values
bool hasDuplicateValues(Node* root, unordered_set<int>& s) {
    if (root == nullptr) {
        return false;
    }

    // If the value is already in the set, return true
    if (s.find(root->data) != s.end()) {
        return true;
    }

    // Insert the value into the set
    s.insert(root->data);

    // Recur for left and right subtrees
    return hasDuplicateValues(root->left, s) || hasDuplicateValues(root->right, s);
}

// Function to check if a binary tree has duplicate values
bool hasDuplicateValues(Node* root) {
    unordered_set<int> s;
    return hasDuplicateValues(root, s);
}

int main() {
    Node* root = nullptr;

    root = buildBinaryTree();

    if (hasDuplicateValues(root)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
