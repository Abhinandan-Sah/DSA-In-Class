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
    
    
    
    bool isEmpty(){
        // return if(top()==NULL)? return true : return false;
        
        if(size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    
    

};

    void sortStack(Stack& st){
        Stack tempStack;
        
        while(!st.isEmpty()){
            int tempVar= st.top();
            st.pop();
            
            while(!tempStack.isEmpty() && tempStack.top() > tempVar){
                st.push(tempStack.top());
                tempStack.pop();
            }
            
            tempStack.push(tempVar);
        }
        
        while(!tempStack.isEmpty()){
            st.push(tempStack.top());
            tempStack.pop();
        }
    }
    
    void displayRev(Stack st){
        Stack temp;
        while(!st.isEmpty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        
    }



int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<"Stack is empty";
        return 0;
    }
    if(n>10){
        cout<<"Stack is full";
        return 0;
    }
    Stack st;
    for(int i=0; i<n; i++){
        int c;
        cin>>c;
        st.push(c);
    }
    
    cout<<"Original stack: ";
    st.display();
    cout<<endl;
    cout<<"Sorted stack: ";
    sortStack(st);
    displayRev(st);
    
    
    return 0;
}