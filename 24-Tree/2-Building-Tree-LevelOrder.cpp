#include<iostream>
#include<queue>
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

Node* buildTree()
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root= new Node(data);

    cout<<"Enter data for left part of "<< data<<" node"<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part of "<< data<<" node"<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL); //This is the main point
    while(!q.empty()){
        Node* temp = q.front();

        q.pop();

        //main code of leveorder Traversal
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";

            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
            q.push(temp->right);
            }
        }

        
    }
}

int main()
{
    Node* root=NULL;
    root=buildTree();
    levelOrderTraversal(root);
    return 0;
}