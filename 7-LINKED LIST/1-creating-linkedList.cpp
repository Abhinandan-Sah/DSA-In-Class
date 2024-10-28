#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};




int main()
{
    //10 20 30 40
    /*Node a;
    a.data=10;
    Node b;
    b.data=20;
    Node c;
    c.data=30;
    Node d;
    d.data = 40;
    */
//    ***OR***
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);


    //forming LL
    a.next = &b;
    b.next = &c;
    c.next = &d;
    // d.next = NULL; //->Now it is not use becoz We have initilize all the next value with NULL

    cout<<"value of b using a: "<<(a.next)->data<<endl; //->printing the value of that is store in next of a which is value of b(20). 
                          //it will print 20;
    //changing b=70 with pointer
    /*a.next->data=70;
    cout<<"After updating val of b: "<<(a.next)->data<<endl; //->o/p-70 (printing value of b using a ka next)
    */

    //printing the value of c with the help of a 
    //printing the value of c with a using old method- 
    //cout<<(*(*(a.next).next).data)<<endl;
    cout<<"value of c using a: "<<((a.next)->next)->data<<endl; //->easy and new method

    //printing the value of d with the help of a
    cout<<"value of d using a: "<<(((a.next)->next)->next)->data<<endl;

    //Printing whole LinkedList
    Node temp=a;
    cout<<"Printing Linked List values: ";
    while(1){
        cout<<temp.data<<" ";
        if(temp.next==NULL) break;
        temp= *(temp.next);
    }
    cout<<endl;
    

   
    return 0;
}