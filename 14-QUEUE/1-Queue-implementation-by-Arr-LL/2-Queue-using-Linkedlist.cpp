// You are using GCC
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

class Queue{
  public:
  Node* front;
  Node* rear;
  int size;
  Queue(){
      front=NULL;
      rear=NULL;
      size=0;
  }
  
  void enqueue(int);
  void display();
};

void Queue::enqueue(int val){
    Node* itemNode= new Node(val);
    if(front==NULL && rear==NULL){
        front=rear=itemNode;
        size++;
    }
    else{
        rear->next=itemNode;
        rear=itemNode;
        size++;
    }
}

void Queue::display(){
    Node*temp=front;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Queue q;
    while(true){
        int item;
        cin>>item;
        if(item==-1){
            break;
        }
        else{
            q.enqueue(item);
        }
    }
    cout<<"Dequeued elements: ";
    q.display();
}