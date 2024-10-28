// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int val){
//         this->val=val;
//         this->next=NULL;
//     }
// };

// class Stack{
//     public:
//     Node* head;
//     int s;
//     Stack(){
//         head=NULL;
//         s=0;
//     }
//     void push(int val){
//         Node* temp=new Node(val);
//         temp->next=head;
//         head=temp;
//         s++;
//     }
//     void pop(){
//         head=head->next;
//         s--;
//     }
//     int top(){
//         return head->val;
//     }
//     int size(){
//         return s;
//     }

//     void print(Node* temp){
//         if(temp==NULL){
//             return;
//         }
//         print(temp->next);
//         cout<<temp->val<<" ";
//     }
//     void display(){
//         Node* temp=head;
//         print(temp);
//     }
// };



// int main()
// {
//     int n;
//     cin>>n;
//     Stack st;
//     for(int i=0; i<n; i++){
//         int c;
//         cin>>c;
//         st.push(c);
//     }
//     cout<<"Orginal stack: ";
//     st.display();
//     cout<<endl;
    
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//     char d= '5';
//     cout<<(int)d;
//     return 0;
// }

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b;
    // cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    ofstream file("even.txt");
    if (file.is_open()) {
        for (int i = a; i <= b; i++) {
            if (i % 2 == 0) {
                file << i << endl;
            }
        }
        file.close();
        // cout << "Even numbers from " << a << " to " << b << " have been written to even.txt." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }

    ifstream readFile("even.txt");
    if (readFile.is_open()) {
        int number;
        // cout << "Contents of even.txt:" << endl;
        while (readFile >> number) {
            cout << number << endl;
        }
        
        readFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }

    return 0;
}
