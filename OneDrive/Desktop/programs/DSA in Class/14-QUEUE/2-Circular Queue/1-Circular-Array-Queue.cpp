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

    void enqueue(int* , int, int);
    void dequeue(int* , int);
    void display(int*, int);
};


void Queue::enqueue(int queue[], int size, int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else if( (rear+1)%size ==front ){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear= (rear+1)%size;
        queue[rear]=item;
    }
};

void Queue::dequeue(int queue[], int size){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty";
    }
    else if(front==rear){
        cout<<"Dequeue element is : "<<queue[front]<<endl;
        front=rear=-1;
    }
    else{
        cout<<"Dequeue element is : "<<queue[front]<<endl;
        front= (front+1)%size;
    }
}

void Queue::display(int queue[], int size){

    int i=front;

    if(front==-1 && rear==-1){
        cout << "Queue is empty" << endl;
        return ;
    }
    else{
        cout<<"Queue is: ";
        while(i!=rear){
            cout<<queue[i]<<" ";
            i=(i+1)%size;
        }
        cout<<queue[i]; //printing last left element when front==rear
    }
    cout<<endl;
}

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
    q.display(queue, n);
    q.dequeue(queue, n);
    q.display(queue, n);


    // int front=q.getFront();
    // cout<<"Front element: "<<queue[front]<<endl;
    // cout<<"Rear element: "<<queue[q.getRear()]<<endl;
    // // int front=-1;
    // // int rear=-1;
    
    // // for(int i=0; i<n; i++){
        
    // // }
    
    return 0;
}