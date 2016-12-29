#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.h"

class Queue {
    public:
        Queue();
        ~Queue();
        void enqueue(int);
        int dequeue();
        bool isEmpty();
        void display();
    private:
        node *front;
        node *rear;
};

#endif
