#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* enqueue(Node* rear, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (rear != NULL) {
        rear->next = temp;
    }
    rear = temp;
    return rear;
}

Node* dequeue(Node* front, Node* rear) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Dequeued customer ID: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }
    return front;
}

void display(Node* front) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Customer IDs in the queue are: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node *front = NULL, *rear = NULL;
    int option, pages;
    while (cin >> option) {
        switch (option) {
            case 1:
                cin >> pages;
                if (front == NULL) {
                    front = rear = enqueue(rear, pages);
                } else {
                    rear = enqueue(rear, pages);
                }
                cout << "Customer ID " << pages << " is enqueued." << endl;
                break;
            case 2:
                front = dequeue(front, rear);
                if (front == NULL) {
                    rear = NULL;
                }
                break;
            case 3:
                display(front);
                break;
            default:
                cout << "Invalid option." << endl;
        }
    }
    return 0;
}

