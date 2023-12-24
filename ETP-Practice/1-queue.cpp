#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int prio;
    Node*next;
    Node(int d, int p){
        this->data=d;
        this->prio=p;
        next=NULL;
    }
};

struct pq{
    Node* front;
    int size;
    pq(){
        front=NULL;
        size=0;
    }

    void Enqueue(int val, int p){
        Node* nn=new Node(val, p);

        if((front==NULL) || front->prio > p){
            nn->next=front;
            front=nn;
        }
        else{
            Node* temp=front;
            while(temp->next != NULL && temp->next->prio <= p ){
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }

    void display(){
        Node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" "<<temp->prio<<endl;
            temp=temp->next;
        }
    }
};


int main()
{
    
    int a;
    int p;
    Node* root=NULL;
    struct pq q;
    
    q.Enqueue(5, 5);
    q.Enqueue(2, 2);
    q.Enqueue(8, 8);
    q.display();
   
    return 0;
}