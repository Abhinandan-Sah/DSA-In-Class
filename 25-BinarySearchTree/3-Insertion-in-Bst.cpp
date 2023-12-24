// You are using GCC
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
  int data;
  struct node*left;
  struct node*right;
  node(int data){
      this->data=data;
      left=NULL;
      right=NULL;
  }
};
// struct node*root;
node* append(node* root, int d)
{
      if(root==NULL){
          return new node(d);
      } 
      
      if(d < root->data){
          root->left = append(root->left, d);
      }
      else{
          root->right= append(root->right, d);
      }
      
      return root;
}
void display(struct node*root)
{
    if(root!=NULL){
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

int main()
{
    node* root=NULL;
  int d;
  do
  {
    cin>>d;
    if(d > 0)
      root=append(root, d);
  }while(d != -1);
  display(root);
  return 0;
}