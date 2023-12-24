#include<iostream>
#include<stack>
using namespace std;


void pushAtBottom(stack<int>& st, int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(x);
}

void reverse(stack<int>& st){
    if(st.size()==1){
        return;
    }
    int x=st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st, x);
}

void displayStack(stack<int>& st){
    if(st.size()==0){
        return;
    }
    int x=st.top();
    st.pop();
    displayStack(st);
    cout<<x<<" ";
    st.push(x);
}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayStack(st);
    cout<<endl;
    reverse(st);
    displayStack(st);
    
 
    return 0;
}