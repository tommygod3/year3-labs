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
    // Node* node = root;
    // while (node->key != key)
    // {
    //     if (isLeaf(node))
    //     {
    //         return nullptr;
    //     }
    //     if (key < node->key)
    //     {
    //         node = node->leftChild;
    //     }
    //     else if (key > node->key)
    //     {
    //         node = node->rightChild;
    //     }
    // }
    // return &node->item;
    
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

BST::~BST()
{
    delete root;
}

bool BST::isLeaf(Node* node)
{
    if (node == nullptr)
    {
        return true;
    }
    return false;
}
