#include<iostream>
#include<stack>
using namespace std;

void displayRev(stack<int>& st){
    if(st.size()==0){
        return;
    }
    int x=st.top();
    cout<<x<<" ";
    st.pop();
    displayRev(st);
    st.push(x);
}
void display(stack<int>& st){
    if(st.size()==0){
        return;
    }
    int x=st.top();
    st.pop();
    displayRev(st);
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
    
    displayRev(st); //IT will print in reverse- 50 40 30 20 10
    cout<<endl;
    display(st);  // It will print in  normal- 10 20 30 40 50
    return 0;
}