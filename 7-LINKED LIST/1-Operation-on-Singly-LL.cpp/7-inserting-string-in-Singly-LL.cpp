#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string val;
    Node* next;
    public:
    Node(string val){
        this->val=val;
        this->next=NULL;
    }
};

class LinkedList{
  public:
  Node* head;
  Node* tail;
  int s;
  LinkedList(){
      head=NULL;
      tail=NULL;
      s=0;
  }
  
  void insertAtHead(string val){
      Node* temp= new Node(val);
      if(s==0){
          head=tail=temp;
      }
      else{
          temp->next=head;
          head=temp;
      }
      s++;
  }
  
  void insertAtEnd(string val){
      Node* temp = new Node(val);
      if(s==0){
          head=tail=temp;
      }
      else{
          tail->next=temp;
          tail=temp;
      }
      s++;
  }
  
  void display(){
      Node* temp = head;
      while(temp!=NULL){
          cout<<temp->val<<" ";
          temp=temp->next;
      }
  }
  
};

int main(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
        
    }
    
    LinkedList ll=  LinkedList();
    for(int i=0; i<n; i++){
        ll.insertAtHead(s[i]);
    }
    cout<<"Document: ";
    ll.display();
    
    return 0;
}