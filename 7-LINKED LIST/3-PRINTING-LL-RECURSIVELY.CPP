#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void disRecur(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    disRecur(head->next);
}


int main()
{
    //creating LL Dynamically
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    disRecur(a);
    return 0;
}