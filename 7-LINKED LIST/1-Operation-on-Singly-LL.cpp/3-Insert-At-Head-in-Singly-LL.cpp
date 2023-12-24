#include<iostream>
using namespace std;

class Node{    //User defined data type
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{   //user defined data structure
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void insertAtEnd(int val){
        Node* temp= new Node(val);
        if(size==0){
            head=tail=temp;
        } 
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node* temp= new Node(val);
        if(size==0){
            head=tail=temp;
        } 
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    LinkedList ll= LinkedList();
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(40);
    ll.display();
    return 0;
}