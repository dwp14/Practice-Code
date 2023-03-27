#ifndef LIST_HPP
#define LIST_HPP

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

class List {
    private:
        Node *head;
        Node *tail;
    public:
        List();
        ~List();
        Node *getHead();
        void setHead(Node *head);
        Node *setTail();
        void setTail(Node *tail);

        void append(int value);
        void prepend(int value);
        void insert(int value);
        void remove(int value);
        Node *search(int value);
        bool isEmpty();
        void print();
};

#endif