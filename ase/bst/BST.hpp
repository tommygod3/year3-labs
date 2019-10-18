#include <iostream>

class BST
{
    public:
        using Key = int;
        using Item = std::string;
    private:
        struct Node;

    friend std::ostream & operator<<(std::ostream & os, const BST & bst);

    public:
        BST() = default;
        ~BST();

        void insert(Key, Item);
        Item* lookup(Key);
        void displayEntries();
        void displayTree();

    private:
        Node* root = nullptr;
        static bool isLeaf(Node*);
        static Item* lookupRec(Key, Node*);
        static void insertRec(Key, Item, Node* &);

        static void displayEntriesRec(Node* node, std::ostream & os);
        void displayTreeRec(Node* node, int depth = 0);
        
        
};

std::ostream & operator<<(std::ostream & os, const BST & bst);
