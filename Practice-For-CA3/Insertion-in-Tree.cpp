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
    Node* insert(Node*, int );
    void display(Node*);   
    Node* search(Node* ,int ); 
    Node* deleted(Node*, int);   
    Node* minVal(Node*);
};

Node* BST::insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(root->data > val){
        root->left= insert(root->left, val);
    }
    else{
        root->right= insert(root->right, val);
    }

    return root;
}

void BST::display(Node* root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

Node* BST::search(Node* root, int item){
    Node* rt=root;
    if(rt==NULL){
        return rt;
    }

    while(rt){
        if(rt->data == item){
            return rt;
        }
        else if(root->data > item){
            rt= search(root->left, item);
        }
        else{
            rt= search(root->right, item);
        }
    }
    return NULL;
}

Node* BST::minVal(Node* root){
    Node* rt=root;
    while(rt->left!=NULL){
        rt=rt->left;
    }
    return rt;
}

Node* BST::deleted(Node* root, int item){
    if(root==NULL){
        return root;
    }
    Node* rt=root;
    if(root->data = item){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }

        //1 child
        if(root->left!=NULL && root->right==NULL){
            Node* temp= root->left;
            delete(root);
            return temp;
        }

        if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }


        //2 child
        if(root->left!=NULL && root->right!=NULL){
            Node* successor= minVal(root->right);
            root->data = successor->data;
            root->right= deleted(root->right, item);
            return root;
        }


    }
    else if(root->data < item){
        root->right= deleted(root->right, item);
    }
    else{
        root->left = deleted(root->left, item);
    }
    return root;
}

int main()
{
    Node* root=NULL;
    int item;
    int c;
    BST b;
    int ele;
    Node* se;
    int del;
    cout<<"For insertion choose 1\n";
    cout<<"For searching choose 2\n";
    cout<<"For Displaying BST choose 3\n";
    cout<<"For deletion choose 4\n";
    while(true){
        cout<<"Enter choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"Enter values: ";
            cin>>item;
            root=b.insert(root, item);
            break;
        case 2:
            cout<<"Enter Element to search: ";
            cin>>ele;
            se= b.search(root, ele);
            if(se==NULL){
                cout<<"No item found"<<endl;
            }
            else{
                cout<<"Item is found is"<<se->data;
            }
            break;
        case 3:
            b.display(root);
            break;
        case 4:
            cout<<"Enter Element to delete: ";
            cin>>del;
            root=b.deleted(root, del);
            break;
        default:
            break;
            // return 0;
        }
    }
    return 0;
}