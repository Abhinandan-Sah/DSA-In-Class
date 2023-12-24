#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST{
    public:
    Node* insert(Node* root, int val){
        if(root==NULL){
            return new Node(val);
        }

        if(root->data > val){
            root->left = insert(root->left, val);
        }
        else{
            root->right = insert(root->right, val);
        }
        return root;
    }

    void display(Node* root){
        if(root!=NULL){
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);
        }
    }
};

int main()
{
    int arr[5]={1, 4, 2, 7, 3};
    Node* root=NULL;
    int n=5;
    BST b;
    for(int i=0; i<n; i++){
        root=b.insert(root,arr[i]);
    }

    b.display(root);
    return 0;
}