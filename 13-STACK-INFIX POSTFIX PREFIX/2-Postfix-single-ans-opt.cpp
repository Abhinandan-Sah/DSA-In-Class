/*
Problem Statement

In a prestigious educational institute, Professor Smith designs a programming challenge for Computer Science students. As part of an assessment on Data Structures and Algorithms, students are presented with a postfix expression that involves mathematical operations.

The challenge requires students to develop a robust algorithm to evaluate these expressions accurately and efficiently. This exercise not only hones their coding skills but also emphasizes the importance of understanding stack-based computations, enhancing their problem-solving capabilities for real-world software development scenarios.
Write a program to evaluate the given postfix expression and display the result.

Note: This is a sample question asked in Infosys recruitment.

Input format :
The input consists of a postfix mathematical expression.

The expression will contain real numbers and mathematical operators (+, -, *, /), without any space.

Output format :
The output prints the result of evaluating the given postfix expression.



Refer to the sample output for formatting specifications.

Code constraints :
The arithmetic operators to be included in the expression are +, -, *, and /.

Sample test cases :
Input 1 :
82/
Output 1 :
4
Input 2 :
545*+5/
Output 2 :
5
Input 3 :
82-4+
Output 3 :
10
*/


#include<iostream>
#include<stack>
#include<string>
#include<typeinfo>
using namespace std;

int calculate(char op, int a, int b){
    if(op == '+'){
        return a + b;
    }
    if(op == '-'){
        return a-b;
    }
    if(op == '*'){
        return a*b;
    }
    if(op == '/'){
        return a/b;
    }
}

int main(){
    string s;
    getline(cin, s);
    stack<int>st;
    for(int i=0; i<s.length(); i++){
        
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            int ans= calculate(s[i], a, b);
            st.push(ans);
        }
    }
    cout<<st.top();
    return 0;
}