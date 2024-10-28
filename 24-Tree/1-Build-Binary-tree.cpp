#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    Node* insertLevelOrder(int arr[], int i, int n) {
    if (i < n) {
        Node* root = new Node(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

    void display(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
        
    display(root->right);
    
}

};

int main()
{
    Node* root=NULL;
    int arr[7]= {10, 6, 16, 5, 8, 14, 20};
    int n=7;
    BST tree;
 
        root = tree.insertLevelOrder(arr, 0, n);

    tree.display(root);
    
    return 0;
}


// // #include<iostream>
// // using namespace std;

// // class Node{
// //     public:
// //     int data;
// //     Node* left;
// //     Node* right;
// //     Node(int val){
// //         this->data=val;
// //         left=NULL;
// //         right=NULL;
// //     }
// // };

// // class BST{
// //     public:
// //     Node* insert(Node* root, int item){
// //        if (start > end) {
// //             return NULL;
// //         }

// //         int mid = (start + end) / 2;
// //         Node* root = new Node(arr[mid]);

// //         root->left = buildTree(arr, start, mid - 1);
// //         root->right = buildTree(arr, mid + 1, end);

// //         return root;
// //     }

// //     void display(Node* root){
// //     if(root==NULL){
// //         return;
// //     }
// //     cout<<root->data<<" ";
// //     display(root->left);
// //     display(root->right);
    
// // }

// // };

// // int main()
// // {
// //     Node* root=NULL;
// //     int arr[7]= {10, 6, 16, 5, 8, 14, 20};
// //     int n=7;
// //     BST tree;
// //     for(int i=0; i<n; i++){
// //         root=tree.insert(root, arr[i]);
// //     }
// //     tree.display(root);
    
// //     return 0;
// // }

// #include<iostream>
// #include<vector>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         this->data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// class BinaryTree {
// public:
//     Node* buildTree(vector<int>& arr, int start, int end) {
//         if (start > end) {
//             return NULL;
//         }

//         int mid = (start + end) / 2;
//         Node* root = new Node(arr[mid]);

//         root->left = buildTree(arr, start, mid - 1);
//         root->right = buildTree(arr, mid + 1, end);

//         return root;
//     }

//     void display(Node* root) {
//         if (root == NULL) {
//             return;
//         }
//         cout << root->data << " ";
//         display(root->left);
//         display(root->right);
//     }
// };

// int main() {
//     vector<int> arr = {10, 6, 16, 5, 8, 14, 20};
//     int n = arr.size();
//     BinaryTree tree;

//     Node* root = tree.buildTree(arr, 0, n - 1);
//     tree.display(root);

//     return 0;
// }
