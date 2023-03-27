#ifndef STACK_HPP
#define STACK_HPP

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

class Stack {
    private:
        Node *head;
        int size;
    public:
        void push(Node *node);
        Node *pop();
        bool isEmpty();
};

#endif