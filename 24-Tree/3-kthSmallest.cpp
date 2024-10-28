/*
Problem Statement



You are given a binary search tree (BST) and an integer k. Your task is to find the kth smallest element in the BST.



Implement the function kthSmallest that takes the root of the BST and an integer k as input and returns the kth smallest element in the BST.

Input format :
The first line of input consists of a sequence of integers representing the elements of the BST. The input is terminated by -1.

The second line consists of an integer k, representing the position of the desired smallest element.

Output format :
The output prints a single integer, which is the kth smallest element in the BST.

Sample test cases :
Input 1 :
20 8 22 4 12 10 14 -1
3
Output 1 :
10
Input 2 :
20 8 4 12 10 14 22 -1
4
Output 2 :
12
*/


// You are using GCC
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


// Function to build a BST from user input
TreeNode* buildBST() {
    int val;
    TreeNode* root = nullptr;

    while (true) {
        cin >> val;

        if (val == -1) {
            break;
        }

        if (root == nullptr) {
            root = new TreeNode(val);
        } else {
            // Insert the value into the BST
            TreeNode* current = root;
            while (true) {
                if (val < current->val) {
                    if (current->left == nullptr) {
                        current->left = new TreeNode(val);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = new TreeNode(val);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    return root;
}

int kthValue;

void kthSmallest(TreeNode* root, int k, int& index) {
    if(!root){
        return;
    }
    kthSmallest(root->left, k, index);
    if(index==k){
        kthValue= root->val;
        index++;
        return;
    }
    else{
        index++;
    }

    kthSmallest(root->right, k, index);
}



int main() {
    TreeNode* root = buildBST();

    int k;
    cin >> k;
    int index=1;
    kthValue=-1;
     kthSmallest(root, k, index);
    cout << kthValue;

    // Clean up memory
    delete root;

    return 0;
}