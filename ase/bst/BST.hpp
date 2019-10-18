#include <iostream>

class BST
{
    public:
        using Key = int;
        using Item = std::string;
    private:
        struct Node;

    public:
        BST() = default;
        ~BST();

        void insert(Key, Item);
        Item* lookup(Key);
        void displayEntries();
        static void displayEntry(Node* node);
        void displayTree();

        template<class T>
        void preOrder(Node* node, T func);
        template<class T>
        void postOrder(Node* node, T func);
        template<class T>
        void inOrder(Node* node, T func);

    private:
        Node* root = nullptr;
        static bool isLeaf(Node*);
        static Item* lookupRec(Key, Node*);
        static void insertRec(Key, Item, Node* &);
        void displayTreeRec(Node* node, int depth = 0);
        
        

};

// Perform a function on each node in specified order:
template<class T>
void BST::preOrder(Node* node, T func)
{
    if (isLeaf(node))
        return;

    func(node);
    preOrder(node->leftChild, func);
    preOrder(node->rightChild, func);
}

template<class T>
void BST::postOrder(Node* node, T func)
{
    if (isLeaf(node))
        return;
    func(node);
    postOrder(node->leftChild, func);
    postOrder(node->rightChild, func);
}

template<class T>
void BST::inOrder(Node* node, T func)
{
    if (isLeaf(node))
        return;
    inOrder(node->leftChild, func);
    func(node);
    inOrder(node->rightChild, func);
}
