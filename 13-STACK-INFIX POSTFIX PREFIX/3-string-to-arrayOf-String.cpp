/*
Problem Statement



Meena is a Computer Science student who is currently studying Data Structures and Algorithms. As part of her assignment, she has been tasked with implementing a program that evaluates postfix expressions using a Stack data structure.



Write a program to help Meena evaluate a given postfix mathematical expression using a Stack.



Example



Input:

10 2 3 + *



Output:

50



Explanation:

exp = 10 2 3 + * 
exp[0]="10" => push() => Stack = 10
exp[1]="2" => push() => Stack = 10 2
exp[2]="3" => push() => Stack = 10 2 3
exp[3]="+" => pop() => Stack = 10 5 (perform addition on first two top-most elements, 3+ 2 = 5)
exp[4]="*" => pop() => Stack = 50 (perform multiplication on first two top-most elements, 10*5 = 50) Print the last value, 50.


Note: This is a sample question asked in Capgemini recruitment.

Input format :
The input consists of a postfix mathematical expression.

The expression will contain integers and arithmetic operators (+, -, *, /) separated by space.

Output format :
The output prints the result of evaluating the given postfix expression.

Code constraints :
The expression may contain only valid mathematical characters: digits and arithmetic operators.
The input expression will only contain integers as operands, and the result will always be within the range of a 32-bit signed integer.
Sample test cases :
Input 1 :
10 2 3 + *
Output 1 :
50
Input 2 :
4 8 *
Output 2 :
32
Input 3 :
5 2 3 * + 8 4 / - 3 +
Output 3 :
12
*/


#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> s;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            // If the token is a digit, push it onto the stack
            s.push(stoi(token));
        } else {
            // If the token is an operator, pop two operands from the stack and perform the operation
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (token[0]) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }

    // The final result will be on top of the stack
    return s.top();
}

int main() {
    string expression;
    // cout << "Enter a postfix expression: ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
