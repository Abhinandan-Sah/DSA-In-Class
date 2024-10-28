#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->left=NULL;
        this->val=val;
        this->right=NULL;
    }
};

class Tree{
    public:
    Node* root;
    Tree(){
        root=NULL;
    }

    void createRoot(int val){
        Node* temp=new Node(val);
        root=temp;
    }

    void display(){
        cout<<"Root: "<<root->val<<endl;
        Node* temp= root->left;
        while(temp!=NULL ){
            cout<<temp->val<<" ";
            temp=temp->left;
        }
        cout<<"\n Printing Right side of Tree"<<endl;
        Node* tempR=root->right;
        while(tempR!=NULL ){
            cout<<tempR->val<<" ";
            tempR=tempR->right;
        }
    }
    
};

int main()
{
    Tree t;
    t.createRoot(5);
    // cout<<t.root->val;
    t.root->left= new Node(6);
    t.root->right=new Node(7);
    t.root->left->left=new Node(8);
    t.root->right->right=new Node(9);

    t.display();
    return 0;
}