// You are using GCC
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Checking precedence
int prec(char c) {
    if (c == '^') {
        return 3;
    } 
     if (c == '*' || c == '/') {
        return 2;
    } 
    if (c == '+' || c == '-') {
        return 1;
    } 
    return 0;
    
}

bool isLeftAssocitivity(char c){
    if(c=='*' || c=='/' || c=='^' || c=='+' || c=='-'){
        return true;
    }
    else{
        return false;
    }
}

string  infixToPostfix(string& s) {
    string ns = "";
    stack<char> st;
    for(int i=0; i< s.length(); i++){
        if(s[i]== ' '){
            continue;
        }
        else if(isupper(s[i])){ //if it is operands
            ns+=s[i];
        }
        else if(s[i]=='('){ //if it is opening breacket
            st.push(s[i]);
        }
        else if(s[i]==')'){   //if it is closing bracket
            while(!st.empty() && st.top() !='('){
                char val=st.top();
                ns+=val;
                st.pop();
                
            }
            
            if(st.top() == '('){
                st.pop();
            }
        }
        else{   //if it is an operand
            while(!st.empty() && prec(s[i]) <= prec(st.top())  ){
                char val=st.top();
                ns+=val;
                st.pop();
            }
            st.push(s[i]);
        }

        // cout<<"ns="<<ns<<endl;
        // cout<<"stack top= "<<st.top()<<endl;
    }
    
    while(!st.empty()){
        char val=st.top();
        ns+=val;
        st.pop();
        
    }
    
    return ns;
}

int main() {
    
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
    string str;
    getline(cin, str); // Read the entire input line
    string postfix = infixToPostfix(str);
    cout<<"Postfix expression "<<i<<": "<<postfix;
    }
    return 0;
}
