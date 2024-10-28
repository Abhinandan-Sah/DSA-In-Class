#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>st){
    stack<int>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }

}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<"Printing stack in Normal order: ";
    print(st);
    stack<int>gt;
    stack<int>rt;
    //empty st into gt
    while(st.size()>0){
        gt.push(st.top());
        st.pop();
    }
    //empty gt into rt
    while(gt.size()>0){
        rt.push(gt.top());
        gt.pop();
    }
    //empty st into gt
    while(rt.size()>0){
        st.push(rt.top());
        rt.pop();
    }
    cout<<endl;
    cout<<"Printing the stack after reversing it: ";
    print(st);
    return 0;
}