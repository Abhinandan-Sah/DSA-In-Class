#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class DLL{
    public:
    Node* head;
    Node* tail;
    int s;
    DLL(){
        head=tail=NULL;
        s=0;
    }

    void insertAtHead(int data){
        Node* newNode= new Node(data);
        if(head==NULL && tail==NULL){
            head=tail=newNode;
            return;
        }

        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void insertAtTail(int data){
        Node* newNode= new Node(data);
        if(head==NULL && tail==NULL){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }

        cout<<"Printing Reverse: "<<endl;
    }
};

int main()
{
    DLL d;
    d.insertAtHead(3);
    d.insertAtHead(2);
    d.display();
    return 0;
}