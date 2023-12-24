#include<iostream>
using namespace std;

class Deque{
    int front;
    int rear;
    public:
    Deque(){
        front=-1;
        rear=-1;
    }

    void enqueueFront(int* , int, int);
    void enqueueRear(int* , int, int);
    void dequeueFront(int* , int);
    void dequeueRear(int* , int);
    int getFront(int*);
    int getRear(int*);
    void display(int*, int);
};


void Deque::enqueueFront(int queue[], int size, int item){
    if((front==0 && rear== size-1) || (front == rear+1)){
        cout<<"Queue is full"<<endl;
    }
    else if( front==-1 && rear==-1 ){   
        front=rear=0;
        queue[rear]=item;
    }
    else if(front==0){
        front=size-1;
        queue[rear]=item;
    }
    else{
        front--;
        queue[front]=item;
    }

};

int Deque::getFront(int queue[]){ 
    if(front==-1 && rear==-1){
        cout<<"Queue is empty."<<endl;
        return 0;
    }else{
        return queue[front]; 
    }
    
}
int Deque::getRear(int queue[]){ 
    if(front==-1 && rear==-1){
        cout<<"Queue is empty."<<endl;
        return 0;
    }else{
        return queue[rear]; 
    }
    
}

void Deque::enqueueRear(int queue[], int size, int item){
    if((front==0 && rear== size-1) || (front == rear+1)){
        cout<<"Queue is full"<<endl;
    }
    else if( front==-1 && rear==-1 ){   
        front=rear=0;
        queue[rear]=item;
    }
    else if(rear==size-1){
        rear=0;
        queue[rear]=item;
    }
    else{
        rear++;
        queue[rear]=item;
    }

};



void Deque::dequeueFront(int queue[], int size){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(front==rear){
        cout<<"Dequeue element is: "<<queue[front]<<endl;
        front=rear=-1;
    }
    else if(front==size-1){
        cout<<"Dequeue element is: "<<queue[front]<<endl;
        front=0;
    }
    else{
        cout<<"Dequeue element is: "<<queue[front]<<endl;
        front++;
    }
}

void Deque::dequeueRear(int queue[], int size){
    if(front==-1 && rear==-1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else if(front==rear){
        cout<<"Dequeue element is: "<<queue[front]<<endl;
        front=rear=-1;
    }
    else if(rear==0){
        cout<<"Dequeue element is: "<<queue[rear]<<endl;
        rear=size-1;
    }
    else{
        cout<<"Dequeue element is: "<<queue[front]<<endl;
        rear--;
    }
}

void Deque::display(int queue[], int size){

    int i=front;

    if(front==-1 && rear==-1){
        cout << "Queue is empty" << endl;
        return ;
    }
    else{
        cout<<"Deque is: ";
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
    Deque q;
    for(int i=0; i<n; i++){
        int item;
        cin>>item;
        // q.enqueue(queue, n, item);
        
    }
    // q.display(queue, n);
    // q.dequeue(queue, n);
    // q.display(queue, n);


    // int front=q.getFront();
    // cout<<"Front element: "<<queue[front]<<endl;
    // cout<<"Rear element: "<<queue[q.getRear()]<<endl;
    // // int front=-1;
    // // int rear=-1;
    
    // // for(int i=0; i<n; i++){
        
    // // }
    
    return 0;
}