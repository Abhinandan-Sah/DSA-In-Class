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

    void enqueue(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            front = rear = temp;
            rear->next = front;
            size++;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front;
            size++;
        }
    }

    void dequeueHead()
    {
        Node *temp = front;
        if (front == NULL && rear == NULL)
        {
            cout << "Underflow condition" << endl;
        }
        else if (front == rear)
        {
            front = rear = NULL;
            delete (temp);
        }
        else
        {
            front = front->next;
            rear->next = front;
            delete (temp);
        }
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
    q.enqueue(12);
    q.enqueue(60);
    q.display();

    return 0;
}