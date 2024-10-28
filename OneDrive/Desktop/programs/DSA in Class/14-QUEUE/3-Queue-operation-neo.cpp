#include<iostream>
using namespace std;

class Node{
  public:
  int val;
  Node* next;
  Node(int val){
      this->val=val;
      this->next=NULL;
  }
};

class Queue{
  public:
  Node* front;
  Node* rear;
  int size;
  Queue(){
      front=NULL;
      rear=NULL;
      size=0;
  }
  
  void enqueue(int);
  void dequeue();
  void display();
};

void Queue::enqueue(int val){
    Node* itemNode = new Node(val);
    if(front == NULL && rear == NULL){
        front = rear = itemNode;
        size++;
    }
    else{
        rear->next = itemNode;
        rear = itemNode;
        size++;
    }
}

void Queue::display(){
    Node* temp = front;
    
    if(front == NULL && temp == NULL){
        cout << "Queue is empty." << endl;
        return;
    }
    
    cout << "Print jobs in the queue: ";
    while(temp != NULL){
        cout << temp->val << " pages ";
        temp = temp->next;
    }
    cout << endl;
}

void Queue::dequeue(){
    if(front == NULL){
        cout << "Queue is empty." << endl;
    }
    else{
        cout << "Processing print job: " << front->val << " pages" << endl;
        front = front->next;
    }
}

int main(){
    Queue q;
    while(1){
        int c;
        cin >> c;
        switch(c){
            case 1:
            int item;
            cin >> item;
            q.enqueue(item);
            cout << "Print job with " << item << " pages is enqueued." << endl;
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.display();
            break;
            default:
            cout << "Invalid option." << endl;
            break;
        }
    }
}
