#include<iostream>
#include<stack>
using namespace std;

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

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    pushAtBottom(st, 5); 
    displayStack(st);
    
 
    return 0;
}