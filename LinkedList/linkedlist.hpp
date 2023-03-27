#ifndef LINKEDLIST_HPP
#define LINKEDlIST_HPP

template <class T>
class Node {
    private:
        T value;
        Node<T> *next;
    public:
        Node();
        T getValue() {return value;};
        void setValue(T value) {this->value = value;};
        T *getNext() {return next;};
        void setNext(Node *next) {this->next = next;};
};

template <class T>
class LinkedList {
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        LinkedList();
        ~LinkedList();

        void append(Node<T> *node);
        void prepend(Node<T> *node);
        void insert(Node<T> *node, Node<T> *newNode);
        void remove(Node<T> *node);
        Node<T> *search(T value);
        bool isEmpty();
        void print();
};

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *node = head;
    Node<T> *next;
    while(node != nullptr) {
        next = node->getNext();
        delete node;
        node = next;
    }
}

template <class T>
void LinkedList<T>::append(Node<T> *node) {
    if(isEmpty()) {
        head = node;
        tail = node;
    }
    else {
        tail->setNext(node);
        tail = node;
    }
}

template <class T>
void LinkedList<T>::prepend(Node<T> *node) {
    if(isEmpty()) {
        head = node;
        tail = node;
    }
    else {
        node->setNext(head);
        head = node;
    }
}

template <class T>
void LinkedList<T>::insert(Node<T> *node, Node<T> *newNode) {
    newNode->setNext(node->getNext());
    node->setNext(newNode);
    if(node == tail) {
        tail = newNode;
    }
}

template <class T>
void LinkedList<T>::remove(Node<T> *node) {
    Node<T> *prevNode;
    if(node == head) { // 1. Check for head. 2. Iterate through entire list to check for node.  3. When found set prevNode's next node as the node that is after node. 4. Check if node was the tail and if so set the new tail as prevNode 5. delete node
        head = head->getNext();
    }
    else {
        prevNode = head;
    }
    while(true) {
        if(prevNode->getNext() == node)
            break;
        prevNode = prevNode->getNext();
    }
    prevNode->setNext(node->getNext());
    if(node == tail) {
        tail = prevNode;
    }
    delete node;
}

template <class T>
Node<T> *LinkedList<T>::search(T value) {
    Node<T> *currNode;
    if(head == nullptr)
        return nullptr

    while(currNode != nullptr) {
        if(currNode->getValue() == value) {
            return currNode;
        }
        currNode = currNode->getNext();
    }
    return nullptr;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    if(head == nullptr)
        return true; 
    else   
        return false;
}

template <class T>
void LinkedList<T>::print() {
    Node *currNode;
    currNode = head;
    while(currNode != nullptr) {
        std::cout << currNode->getValue() << std::endl;
        currNode = currNode->getNext();
    }
}

#endif