#include "BST.hpp"

struct BST::Node
{
    Key key;
    Item item;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;

    Node(Key keyIn, Item itemIn)
    {
        key = keyIn;
        item = itemIn;
    }

    ~Node()
    {
        delete leftChild;
        delete rightChild;
    }
};

void BST::insert(Key key, Item item)
{
    insertRec(key, item, root);
}

void BST::insertRec(Key key, Item item, Node* & current)
{
    if (isLeaf(current))
    {
        current = new Node(key, item);
    }
    else if (current->key == key)
    {
        current->item = item;
    }
    else if (key < current->key)
    {
        insertRec(key, item, current->leftChild);
    }
    else if (key > current-> key)
    {
        insertRec(key, item, current->rightChild);
    }
}

BST::Item* BST::lookup(Key key)
{
    return lookupRec(key, root);
}

BST::Item* BST::lookupRec(Key key, Node* node)
{
    if (isLeaf(node))
    {
        return nullptr;
    }
    if (node->key == key)
    {
        return &node->item;
    }
    if (key < node->key)
    {
        lookupRec(key, node->leftChild);
    }
    else if (key > node->key)
    {
        lookupRec(key, node->rightChild);
    }
}

void BST::displayEntries()
{
    // Which is better? Is this func even needed?

    //std::cout << *this;

    displayEntriesRec(root, std::cout);
}

void BST::displayEntriesRec(Node* node, std::ostream & os)
{
    if (isLeaf(node))
        return;
    displayEntriesRec(node->leftChild, os);
    os << node->key << ' ' << node->item << '\n';
    displayEntriesRec(node->rightChild, os);
}

void BST::displayTree()
{
    displayTreeRec(root);
}

void BST::displayTreeRec(Node* node, int depth)
{
    if (isLeaf(node))
    {
        std::cout << std::string(depth, '.') << '*' << '\n';
        return;
    }
    std::cout << std::string(depth, '.') << node->item << '\n';
    int nextDepth = ++depth;
    displayTreeRec(node->leftChild, nextDepth);
    displayTreeRec(node->rightChild, nextDepth);
}

bool BST::isLeaf(Node* node)
{
    return node == nullptr;
}

BST::~BST()
{
    delete root;
}

std::ostream & operator<<(std::ostream & os, const BST & bst)
{
    bst.displayEntriesRec(bst.root, os);
}
