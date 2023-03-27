#ifndef QUEUE_HPP
#define QUEUE_HPP

class Node {
    int value;
    Node *next;
    public:
        Node();
        Node(int value);
        int getValue();
        void setValue();
        Node *getNext();
        void setNext(Node *next);
};

class Queue {
    private:
        Node *head;
        Node *tail;
    public:
        Queue();
        ~Queue();
        void enqueue(Node *node);
        Node *dequeue();
        bool isEmpty();
};

#endif