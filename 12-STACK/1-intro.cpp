#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Create a stack
  stack<int> myStack;
  // myStack.size();
  // Push elements onto the stack
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  
  cout<<"Size of stack: "<<myStack.size()<<endl;

  // Pop elements from the stack
  cout << myStack.top() << endl;
  myStack.pop();
  cout << myStack.top() << endl;
           
  myStack.pop();
  cout << myStack.top() << endl;
  myStack.pop();

  return 0;
}