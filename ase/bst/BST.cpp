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

// TODO: Would it not be easier to make a "lookupNode" function which lookups and returns whole node?
// It would simplify a few functions.
void BST::remove(Key key)
{
    removeRec(key, root);
}

void BST::removeRec(Key key, Node* & current)
{
    // Key not in Tree
    if (isLeaf(current))
        return;

    if (current->key == key)
    {
        if (isLeaf(current->leftChild) and isLeaf(current->rightChild))
        {
            delete current;
            current = nullptr;
        }
        else if (isLeaf(current->leftChild) != isLeaf(current->rightChild))
        {
            Node* child;
            if (current->leftChild)
            {
                child = current->leftChild;
            }
            else
            {
                child = current->rightChild;
            }
            
            delete current;
            current = child;
        }
        else if (current->leftChild and current->rightChild)
        {
            BST::Node* newNode = detachMinimumNode(current->rightChild);
            newNode->leftChild = current->leftChild;
            newNode->rightChild = current->rightChild;

            delete current;
            current = newNode;
        }
        return;
    }
    else if (key < current->key)
    {
        removeRec(key, current->leftChild);
    }
    else if (key > current-> key)
    {
        removeRec(key, current->rightChild);
    }
}

BST::Node* BST::detachMinimumNode(Node* & node)
{
    if (isLeaf(node->leftChild))
    {
        BST::Node* nodeCopy = new Node(node->key, node->item);
        removeRec(node->key, node);
        return nodeCopy;
    }
    else
    {
        return detachMinimumNode(node->leftChild);
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

void BST::deepDelete(Node* node)
{
    if (isLeaf(node))
        delete node;
        return;
    if (not isLeaf(node->leftChild))
    {
        deepDelete(node->leftChild);
    }
    if (not isLeaf(node->rightChild))
    {
        deepDelete(node->rightChild);
    }
    delete node;
}

BST::Node* BST::deepCopy(Node* original)
{
    if (isLeaf(original))
        return nullptr;

    Node* node = new Node(original->key, original->item);
    if (not isLeaf(original->leftChild))
    {
        node->leftChild = deepCopy(original->leftChild);
    }
    if (not isLeaf(original->rightChild))
    {
        node->rightChild = deepCopy(original->rightChild);
    }
    return node;
}

BST::BST(const BST & original)
{
    this->root = deepCopy(original.root);
}

BST::~BST()
{
    deepDelete(root);
}

std::ostream & operator<<(std::ostream & os, const BST & bst)
{
    bst.displayEntriesRec(bst.root, os);
}
