#include<iostream>
using namespace std;

void enqueue(int queue[],int size, int item, int &front, int &rear){

    if(rear == size-1){
        cout<<"queue overflow";
        return;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=item;
        cout<<item<<" inserted successfully."<<endl;
    }
    else{
        rear++;
        queue[rear] = item;
        cout<<item<<" inserted successfully."<<endl;
    }
}

void dequeue(int queue[], int &front, int &rear){
    if(front==-1 && rear==-1){
        cout << "UnderFlow occurs"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void peek(int queue[], int front, int rear){
    if(front==-1 && rear==-1){
        cout << "Queue is empty" ;
    }
    else{
        cout<<"Peek element is: "<<queue[front]<<endl;
    }
}

void display(int queue[],int front, int rear){
    if(front==-1 && rear==-1){
        cout << "Queue is empty" << endl;
        return ;
    }
    else{
        for(int i=front; i<rear+1; i++){
        cout<<queue[i]<<" ";
        }
        cout<<"\n";
    }
    
}

int main()
{   int n=5;
    int queue[n];
    int front=-1;
    int rear=-1;
    enqueue(queue, n, 7, front, rear);
    enqueue(queue, n, 11, front, rear);
    enqueue(queue, n, 4, front, rear);
    display(queue, front, rear);
    peek(queue, front, rear);
    dequeue(queue, front, rear);
    display(queue, front, rear);

    
    return 0;
}