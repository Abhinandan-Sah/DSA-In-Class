#include<iostream>
using namespace std;

class Stack{
    public:
    int arr[4];
    int idx;
    Stack(){
        idx=-1;
    }

    void push(int val){
        if(idx==(sizeof(arr)/sizeof(arr[0]))-1){
            cout<<"Stack Overflow"<<endl; 
            return;
        }
        idx++;
        arr[idx]=val;
    }

    void pop(){
        if(idx==-1){
            cout<<"\nStack is Empty\n";  // Underflow is a condition when the stack is empty.
            return;
        }
        idx--;
    }

    int top(){
        // cout<<arr[idx]<<" ";
        return arr[idx];
    }

    int size(){
        // cout << "Size of stack is "<< (idx+1) <<" elements."<<endl;
        return idx+1;
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<"Size: "<<st.top()<<endl; 
    st.pop();
    cout<<"Size: "<<st.size()<<endl; 
    
    return 0;
}