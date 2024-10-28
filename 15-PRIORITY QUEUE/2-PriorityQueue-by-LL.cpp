#include<iostream>
using namespace std;

class Node{
    public:
    int priority;
    int val;
    Node* next;
    Node(int val, int priority){
        this->val = val;
        this->priority=priority;
        this->next=NULL;
    }
};

class priorityQueue{
    public:
    Node *front,*rear;
    int size;
    priorityQueue(){
        this->front=NULL;
        this->rear=NULL;
        size=0;
    }

    void enqueue(int val, int p){
        //inserting as Lower number has higher priority
        Node* nn=new Node(val, p);
        if((front==NULL) || p < front->priority){  //if priority of previous Node(front node)  >  upcomming new Node
            nn->next=front;                        // Here upcomming node priority is higher
            front=nn;
        }
        else{   // priority of current front node is higher(lower number higher priority) than upcomming node
            Node* temp=front;
            while(temp->next!=NULL && temp->next->priority <= p){
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }

    void dequeueAtHead(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }

    void display(){
        Node*temp=front;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    priorityQueue pq;
    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.display();
    pq.dequeueAtHead();
    pq.display();
    pq.dequeueAtHead();
    return 0;
}