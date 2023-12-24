/*
Problem Statement



You are tasked with managing a database of company employees, and you have received a list of employee IDs as integers. 



These IDs have already been used to create a binary tree, but this tree may not adhere to the rules of a Binary Search Tree (BST), where each node follows specific ordering:

For any given node, all nodes in its left subtree must have values less than the node's value
All nodes in its right subtree must have values greater than the node's value.


Your goal is to develop a program that calculates the minimum number of swaps required to transform the existing binary tree into a valid Binary Search Tree (BST).

Input format :
The first line of input consists of an integer N, representing the number of employee IDs in the binary tree.

The second line consists of N values separated by space, representing the unordered employee IDs in the binary tree.

The input is terminated by entering -1.

Output format :
The output prints an integer representing the minimum number of swaps required to convert the unordered list of employee IDs into a valid BST.

Code constraints :
1 < N <= 100

1 <= ID <= 100

Sample test cases :
Input 1 :
5
3 1 5 2 4 -1
Output 1 :
2
Input 2 :
7
4 2 1 3 6 5 7 -1
Output 2 :
6
Input 3 :
6
10 5 2 7 12 15 -1
Output 3 :
3
*/


// // You are using GCC
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the binary tree 
TreeNode* buildTree(int arr[], int& index, int n) {
    if (index >= n || arr[index] == -1) {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(arr[index]);
    index++;
    root->left = buildTree(arr, index, n);
    root->right = buildTree(arr, index, n);

    return root;
}

// Inorder traversal to get the elements in sorted order
void inorder(TreeNode* root, vector<int>& v) {
    if (!root) {
        return;
    }
    inorder(root->left, v);
     v.push_back(root->val);
    inorder(root->right, v);
}

// Function to find the minimum number of swaps to convert BST
int minSwapsToBST(TreeNode* root) {
    
    vector<int> v;
    inorder(root, v);
    vector<int> sortedV = v;
    sort(sortedV.begin(), sortedV.end());
    
    int swaps = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != sortedV[i]) {
            swaps++;
            swap(v[i], v[find(v.begin(), v.end(), sortedV[i]) - v.begin()]);
        }
    }
    
    return swaps;


}

int main() {
    int n;
    cin >> n;

    int arr[100]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = 0;
    TreeNode* root = buildTree(arr, index, n);

    int swaps = minSwapsToBST(root);
    cout << swaps << endl;

    return 0;
}



