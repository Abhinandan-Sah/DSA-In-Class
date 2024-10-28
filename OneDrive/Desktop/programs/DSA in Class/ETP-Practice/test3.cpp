#include<bits/stdc++.h>
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

class LinkedList{
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=NULL;
        tail=NULL;
        size=0; 
    }
    
    void insertAtTail(int val){
        Node* t= new Node(val);
        if(size==0){
            head=tail=t;
        }
        else{
            tail->next=t;
            tail=t;
        }
        size++;
    }
    
    void sumLL(){
        
    }
    
    int display(int ind){
        if(ind>size){
            return;
        }
        Node* temp=head;
        for(int i=0; i<size-ind; i++){
            temp=temp->next;
        }
        int sum=0;
        while(temp!=NULL){
            sum+=temp->val;
            temp=temp->next;
        }
        return sum;
    }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    LinkedList ll= LinkedList();
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ind;
    cin>>ind;
    for(int i=0; i<n; i++){
        ll.insertAtTail(arr[i]);
    }
    
    cout<<ll.display(ind);
    
    return 0;
}