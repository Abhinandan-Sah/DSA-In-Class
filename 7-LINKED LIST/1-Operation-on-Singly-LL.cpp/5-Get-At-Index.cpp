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

    void insertAtIndex(int index, int val){
        
        if(index<0 || index>size){
            cout<<"Index of out of LL";
        }
        else if(index==0){
            insertAtHead(val);
        }
        else if(index==size){
            insertAtEnd(val);
        }
        else{
            Node*temp=head;
            Node* t=new Node(val);
            for(int i=1; i<=index-1; i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
        }
    }

    int getAtIndex(int idx){
        if(idx<0 || idx>=size){
            cout<<"Index of out of LL";
            return -1;
        }
        else if(idx==0){
            return head->val;
        }
        else if(idx==size-1){
            return tail->val;
        }
        else{
            Node*temp=head;
            
            for(int i=1; i<=idx; i++){
                temp=temp->next;
            }
            return temp->val;
        }
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
    ll.insertAtHead(40);
    ll.insertAtIndex(2, 60);
    ll.display();
    cout<<endl;

    int idxVal=ll.getAtIndex(2);
    cout<<idxVal<<endl;
    return 0;
}