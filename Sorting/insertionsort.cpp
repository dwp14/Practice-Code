/*====== insertion sort using arrays ========*/

void insertionsort(int *arr, int size) {
    int i;
    int j;
    int temp;

    for(i = 0; i < size; ++i) {
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]) {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            --j;
        }
    }
}

/*========= insertion sort using linked lists ==========*/

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

        void insertionSort();
        void sortedInsert(Node *node);
};

void List::insertionSort() {
    Node *newHead = head;
    head = nullptr;
    Node *current = newHead;
    Node *next;

    while(current != nullptr) {
        next = current->getNext();
        current->setNext(nullptr);
        sortedInsert(current);
        current = next;
    }
}
void List::sortedInsert(Node *node) {
    if(head == nullptr || node->getValue() <= head->getValue()) {
        node->setNext(head);
        head = node;
    }
    else {
        Node *current = head;
        while(current->getNext() != nullptr && current->getNext()->getValue() < node->getValue()) 
            current = current->getNext();
        node->setNext(current->getNext());
        current->setNext(node);
    }
}
