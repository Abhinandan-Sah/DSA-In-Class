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

class Stack{
    public:
    Node* head;
    int s;
    Stack(){
        head=NULL;
        s=0;
    }
    void push(int val){
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        s++;
    }
    void pop(){
        head=head->next;
        s--;
    }
    int top(){
        return head->val;
    }
    int size(){
        return s;
    }

    void print(Node* temp){
        if(temp==NULL){
            return;
        }
        print(temp->next);
        cout<<temp->val<<" ";
    }
    void display(){
        Node* temp=head;
        print(temp);
    }
};



int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    cout<<endl;
    cout<<st.size()<<endl;
    st.pop();
    st.display();
    cout<<endl;
    cout<<st.size()<<endl;
    return 0;
}