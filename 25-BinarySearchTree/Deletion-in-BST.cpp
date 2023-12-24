#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class BST{
    public:
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }

        if(data < root->data){
            root->left= insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
        return root;
    }

    Node* minVal(Node* root){
        Node* temp= root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Node* maxVal(Node* root){
        Node* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }

    Node* deleteFromBST(Node* root, int val){
        //base case
        if(root==NULL){
            return root;
        }

        if(root->data == val){

            // 0 child
            if(root->left== NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            

            // 1 child

            // left
            if(root->left!=NULL && root->right==NULL){
                Node* temp= root->left;
                delete root;
                return temp;
            }

            //right
            if(root->right!=NULL && root->left==NULL){
                Node* temp= root->right;
                delete root;
                return temp;
            }

            // 2 child
            if(root->right!=NULL && root->left!=NULL){
                Node* succsessor = minVal(root->right);
                root->data= succsessor->data;
                root->right = deleteFromBST(root->right, succsessor->data);
                return root;
            }


        }
        else if(root->data >val){
            root->left = deleteFromBST(root->left, val);
        }
        else{
            root->right = deleteFromBST(root->right, val);
        }
        return root;
    }

    void inorder(Node* root){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
        
    }
    
};

int main(){
    Node* root=NULL;
    BST b;
    int arr[7]= {50, 20, 70, 10, 30, 90, 110};
    for(int i=0; i<7; i++){
        root=b.insert(root,arr[i]);
    }

    b.inorder(root);
    cout<<endl;
    root= b.deleteFromBST(root, 30);
     b.inorder(root);


    return 0;
}