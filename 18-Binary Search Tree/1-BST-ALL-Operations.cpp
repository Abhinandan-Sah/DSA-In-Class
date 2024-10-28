// You are using GCC
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

class BST{
  private:
  node *root;
  public:
  BST(){
      root = NULL;
  }
  int isempty(){return root == NULL;}
  void insert(int);
  void inordertrav();
  void inorder(node*);
  void preordertrav();
  void preorder(node*);
  void postordertrav();
  void postorder(node*);
  node* search(int item){
      node *rt = root;
      if(rt == NULL){
          return NULL;
      }
      while(rt){
          if(item == rt->data){
              return rt;
          }
          else if(item > rt->data){
              rt = rt->right;
          }
          else{
              rt = rt->left;
          }
      }
      return NULL;
  }
};

void BST::insert(int item){
    node *p = new node;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    node *parent = NULL;
    if(isempty()){
        root = p;
    }
    else{
        node *ptr = root;
        while(ptr != NULL){
            parent = ptr;
            if(item < ptr->data){
                ptr = ptr->left;
            }
            else{
                ptr = ptr->right;
            }
        }
        if(item < parent->data){
            parent->left = p;
        }
        else{
            parent->right = p;
        }
    }
}

void BST::inordertrav(){
    inorder(root);
}

void BST::inorder(node *ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        cout<<" "<<ptr->data<<" ";
        inorder(ptr->right);
    }
}

void BST::preordertrav(){
    preorder(root);
}

void BST::preorder(node *ptr){
    if(ptr != NULL){
        cout<<" "<<ptr->data<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BST::postordertrav(){
    postorder(root);
}

void BST::postorder(node *ptr){
    if(ptr != NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<" "<<ptr->data<<" ";
    }
}


int main(){
    int ch, item, ele;
    BST tree;
    while(1){
        cout<<"\nChoice: 1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Search 6.Exit: ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"\nEnter item: ";
            cin>>item;
            tree.insert(item);
            break;
            case 2:
            cout<<"\nInorder is: ";
            tree.inordertrav();
            break;
            case 3:
            cout<<"\nPreorder is: ";
            tree.preordertrav();
            break;
            case 4:
            cout<<"\nPostorder is: ";
            tree.postordertrav();
            break;
            case 5:{
                cout<<"\nEnter item you want to search: ";
                cin>>ele;
                node *sn = tree.search(ele);
                if(sn == NULL){
                    cout<<"\nNode "<<ele<<" not found.";
                }
                else{
                    cout<<"\nNode "<<sn->data<<" found.";
                }
                break;
            }
            case 6:
            exit(0);
            break;
            default:
            cout<<"\nwrong choice entered\n";
            break;
        }
    }
    return 0;
}

