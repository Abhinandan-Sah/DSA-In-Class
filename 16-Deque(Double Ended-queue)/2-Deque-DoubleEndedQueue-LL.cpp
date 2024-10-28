//The code isn't completed

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *front, *rear;
    int size;
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
        size = 0;
    }

    void enqueueFront(int val)
    {
        Node* nn= new Node(val);
        if( (front==NULL && rear==NULL) && (front== rear+1) ){
            cout<<"Queue is full"<<endl;
        }
        else if(front==NULL && rear==NULL){
            front=rear=nn;
        }
        else{
            nn->next=front;
            front=nn;
        }
    }

    void dequeueHead()
    {
        
    }

    void display()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            do
            {
                cout << temp->val << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }
};

int main()
{
    Queue q;

    q.display();

    return 0;
}