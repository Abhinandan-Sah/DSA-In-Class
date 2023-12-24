#include<iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    
    int getFront();
    int getRear();
    void enqueue(int* , int, int);
    // void display(int* , int);
    
};

int Queue::getFront(){
    return front;
}
int Queue::getRear(){
    return rear;
}
void Queue::enqueue(int queue[], int size, int item){
    if(rear== size-1){
        cout<<"overflow"<<endl;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else{
        rear++;
        queue[rear]=item;
    }
};

int main(){
    int n;
    cin>>n;
    int queue[n];
    Queue q;
    for(int i=0; i<n; i++){
        int item;
        cin>>item;
        q.enqueue(queue, n, item);
        
    }
    int front=q.getFront();
    cout<<"Front element: "<<queue[front]<<endl;
    cout<<"Rear element: "<<queue[q.getRear()]<<endl;
    // int front=-1;
    // int rear=-1;
    
    // for(int i=0; i<n; i++){
        
    // }
    
    return 0;
}