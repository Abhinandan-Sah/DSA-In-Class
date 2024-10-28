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

void pushAtIdx(stack<int>& st, int idx, int v){
    stack<int>temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(v);
    //Again filling st
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
    
}
void pushAtBottom(stack<int>& st, int v){
    stack<int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    st.push(v);
    //Again filling st
    while(temp.size()>0){
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
    // st.push(40);
    // st.push(50);
    cout<<"Enter element to put at Bottom: ";
    int v;
    cin>>v;
    cout << "Before pushing: ";
    print(st);
    pushAtBottom(st, v);
    // st.pop();
    // cout<<endl<<st.top()<<endl;
    cout << "\nAfter Pushing: ";
    print(st);
    cout<<"\nAfter pushing at index: ";
    pushAtIdx(st, 2, 25);
    print(st);
    return 0;
}