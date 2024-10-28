#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>& st){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
        
    }
    cout<<endl;

    while(temp.size()>0){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }

    
}

void reverse(stack<int>& st){
    // st.push(st.pop());
}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    reverse(st);
    print(st);
    return 0;
}