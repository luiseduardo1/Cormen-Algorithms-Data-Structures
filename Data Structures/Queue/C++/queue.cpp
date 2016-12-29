#include "queue.hpp"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    delete front;
}

void Queue::enqueue(int data) {
    node *temp = new node();
    temp->data = data;
    temp->next = nullptr;

    if (front == nullptr) {
        front = temp;
    } else {
        rear->next = temp;
    }

    rear = temp;
}

int Queue::dequeue() {
    node *temp = new node();
    int value;

    if(front == nullptr) {
        cout << "\n The queue is empty \n";
    } else {
        temp = front;
        value = temp->data;
        front = front->next;
        delete temp;
    }

    return value;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::display() {
    node *p = new node;
    p = front;

    if(front == nullptr) {
        cout << "\n The queue is empty \n";
    } else {
        while (p! == nullptr) {
            cout << p->data << endl;
            p = p->next;
        }
    }
}
