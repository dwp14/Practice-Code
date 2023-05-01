class BST {
    private:
        Node* root;
        void deleteSubtree(Node* root) {
            if(root == nullptr)
                return;
            deleteSubtree(root->getLeft());
            deleteSubtree(root->getRight());
            delete root;
            root = nullptr;
        }
    public:
        BST(Node *root = nullptr) {
            this->root = root;
        } 
        void insert(int value) {
            if(root == nullptr) 
                root = new Node(value);
            else {
                Node* current = root;
                while(current != nullptr) {
                    if(value < current.getData())
                        if(current.getLeft() == nullptr) {
                            current->setLeft(new Node(value));
                            return;
                        }
                        else {
                            current = current->getLeft();
                        }
                    else {
                        if(current->getRight() == nullptr) {
                            current->setRight(new Node(value));
                            return;
                        }    
                        else 
                            current = current->getRight();
                    }
                }
            }
        }

        bool search(int value) {
            Node* current = root;
            while(current != nullptr) {
                if(value == current->getData()) {
                    return true;
                }
                else if(value < current->getData())
                    current = current->getLeft();
                else 
                    current = current->getRight();
            }
            return false;
        }
        ~BST() {
            deleteSubtree(root);
        }
}