#include <iostream>

template < typename T1, typename T2 >
class BST
{
    public:
        using Key = T1;
        using Item = T2;
    private:
        struct Node;

    template < typename TF1, typename TF2 >
    friend std::ostream & operator<<(std::ostream & os, const BST<TF1, TF2> & bst);

    public:
        // Defeault Constructor
        BST() = default;
        // Copy Constructor
        BST(const BST<T1, T2> &);
        // Copy Assignment Operator
        BST<T1, T2> & operator=(const BST<T1, T2> &);
        // Move Constructor
        BST(BST<T1, T2> &&);
        // Move Assignment Operator
        BST<T1, T2> & operator=(BST<T1, T2> &&);
        // Destructor
        ~BST();

        Item* lookup(Key);
        void insert(Key, Item);

        void displayTree();

        void remove(Key);

    private:
        Node* root = nullptr;
        static bool isLeaf(Node*);

        static Item* lookupRec(Key, Node*);
        static void insertRec(Key, Item, Node* &);

        static void displayEntriesRec(Node* node, std::ostream & os);
        void displayTreeRec(Node* node, int depth = 0);

        static void removeRec(Key, Node* &);

        static Node* detachMinimumNode(Node* &);

        static void deepDelete(Node*);

        static Node* deepCopy(Node*);

        // The Node argument here must be an internal node and so must it's left child
        static void rotateRight(Node* &);
        // The Node argument here must be an internal node and so must it's right child
        static void rotateLeft(Node* &);
        // Return value indicates if sub-tree height decreased
        static bool rebalance(Node* &); 
};

template < typename T1, typename T2 >
std::ostream & operator<<(std::ostream & os, const BST<T1, T2> & bst);

#include "BST.ipp"
