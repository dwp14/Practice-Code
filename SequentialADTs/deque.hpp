#ifndef DEQUE_HPP
#define DEQUE_HPP

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

class Deque {
    public:
        void pushFront(Node *node);
        void pushBack(Node *node);
        Node *popFront();
        Node *popBack();
        bool isEmpty();
};

#endif