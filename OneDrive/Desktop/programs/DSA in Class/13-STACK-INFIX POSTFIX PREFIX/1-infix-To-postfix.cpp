/*
Problem Statement

Kiruthika is working on a programming project that requires the conversion of infix mathematical expressions into postfix notation. To accomplish this task efficiently, she seeks your assistance in developing a program.

Your goal is to create a program that accepts an infix expression as input and converts it into postfix notation. Kiruthika is interested in a program that can handle various arithmetic operations, parentheses, and operands within the input expression.

Note: This is a sample question asked in a Deloitte interview.

Input format :
The input consists of the infix expression and arithmetic operators (+, -, *, /), and parentheses () with a single space.

Output format :
The output prints the postfix expression of the input expression without any space.

Code constraints :
The input includes (, ), +, -, * / and upper alphabets.

Sample test cases :
Input 1 :
(A + (B * C))
Output 1 :
ABC*+
Input 2 :
 A / D - E
Output 2 :
AD/E-
*/


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

        
    }
    
    while(!st.empty()){
        char val=st.top();
        ns+=val;
        st.pop();
        
    }
    
    return ns;
}

int main() {
    string str;
    getline(cin, str); // Read the entire input line
    string postfix = infixToPostfix(str);
    cout<<postfix;
    return 0;
}
