#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node{    //User defined data type
    public:
    string val;
    Node* next;
    Node(string val){
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

    void insertAtEnd(string val){
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

    

};

void revDisplay(Node* temp){
        if(temp==NULL) return;
        revDisplay(temp->next);
        cout<<temp->val<<" ";
}

int main()
{
    int n;
    cin>>n;
    vector<string>str(n);
    for(int i=0; i<n;i++){
        cin>>str[i];
    }
    string x;
    cin>>x;
    LinkedList ll= LinkedList();
    for(int i=0; i<n; i++){
        ll.insertAtEnd(str[i]);
    }
    Node* head1=ll.head;
    cout<<"LL before insertion: ";
    revDisplay(head1);   
    cout<<endl;
    ll.insertAtEnd(x);
    cout<<"LL After insertion: ";
    revDisplay(head1);
     

    
    return 0;
}