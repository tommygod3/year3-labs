#include <cassert>
#include <algorithm>

template < typename T1, typename T2 >
struct BST<T1, T2>::Node
{
    Key key;
    Item item;
    int balanceFactor;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;

    Node(Key keyIn, Item itemIn, int balanceFactorIn = 0)
    {
        key = keyIn;
        item = itemIn;
        balanceFactor = balanceFactorIn;
    }
};

template < typename T1, typename T2 >
void BST<T1, T2>::insert(Key key, Item item)
{
    insertRec(key, item, root);
}

template < typename T1, typename T2 >
bool BST<T1, T2>::insertRec(Key key, Item item, Node* & current)
{

    if (isLeaf(current))
    {
        current = new Node(key, item);
        return true;
    }
    // Assert tree in balanced state
    assert(current->balanceFactor < 2);
    assert(current->balanceFactor > -2);
    if (key < current->key)
    {
        bool subTreeHeightIncrease = insertRec(key, item, current->leftChild);
        if (not subTreeHeightIncrease) return false;
        current->balanceFactor =- 1;
        if (current->balanceFactor == -2)
        {
            assert(rebalance(current));
            return false;
        }
        else if (current->balanceFactor == -1) return true;
        else if (current->balanceFactor == 0) return false;
        assert(false);
    }
    else if (key > current->key)
    {
        bool subTreeHeightIncrease = insertRec(key, item, current->rightChild);
        if (not subTreeHeightIncrease) return false;
        current->balanceFactor += 1;
        if (current->balanceFactor == 2)
        {
            assert(rebalance(current));
            return false;
        }
        else if (current->balanceFactor == 1) return true;
        else if (current->balanceFactor == 0) return false;
        assert(false);
    }
    // If we are here the key must be the same
    assert(current->key == key);
    current->item = item;
    return false;
}

template < typename T1, typename T2 >
typename BST<T1, T2>::Item* BST<T1, T2>::lookup(Key key)
{
    return lookupRec(key, root);
}

template < typename T1, typename T2 >
typename BST<T1, T2>::Item* BST<T1, T2>::lookupRec(Key key, Node* node)
{
    if (isLeaf(node))
    {
        return nullptr;
    }
    else if (key < node->key)
    {
        return lookupRec(key, node->leftChild);
    }
    else if (key > node->key)
    {
        return lookupRec(key, node->rightChild);
    }
    assert(node->key == key);
    return &node->item;
}

template < typename T1, typename T2 >
void BST<T1, T2>::remove(Key key)
{
    removeRec(key, root);
}

template < typename T1, typename T2 >
bool BST<T1, T2>::removeRec(Key key, Node* & current)
{
    // Key not in Tree
    if (isLeaf(current)) return false;
    // Assert tree in balanced state
    assert(current->balanceFactor < 2);
    assert(current->balanceFactor > -2);

    if (key < current->key)
    {
        bool heightDecrease = removeRec(key, current->leftChild);
        if (not heightDecrease) return false;
        current->balanceFactor += 1;
        if (current->balanceFactor == 0) return true;
        if (current->balanceFactor == 1) return false;
        if (current->balanceFactor == 2) return rebalance(current);
    }
    else if (key > current->key)
    {
        bool heightDecrease = removeRec(key, current->rightChild);
        if (not heightDecrease) return false;
        current->balanceFactor -= 1;
        if (current->balanceFactor == 0) return true;
        if (current->balanceFactor == -1) return false;
        if (current->balanceFactor == -2) return rebalance(current);
    }

    assert(current->key == key);
    
    if (isLeaf(current->leftChild) and isLeaf(current->rightChild))
    {
        delete current;
        current = nullptr;
        return true;
    }
    else if (isLeaf(current->leftChild) != isLeaf(current->rightChild))
    {
        Node* child;
        if (current->leftChild) child = current->leftChild;
        else child = current->rightChild;
        
        delete current;
        current = child;
        return true;
    }
    else if (current->leftChild and current->rightChild)
    {
        std::pair<bool, BST<T1, T2>::Node*> returnPair = detachMinimumNode(current->rightChild);
        bool heightDecrease = returnPair.first;
        BST<T1, T2>::Node* newNode = returnPair.second;

        newNode->leftChild = current->leftChild;
        newNode->rightChild = current->rightChild;

        delete current;
        current = newNode;
        return heightDecrease;
    }
    assert(false);
}

template < typename T1, typename T2 >
std::pair<bool, typename BST<T1, T2>::Node*> BST<T1, T2>::detachMinimumNode(Node* & node)
{
    if (isLeaf(node->leftChild))
    {
        BST<T1, T2>::Node* nodeCopy = new Node(node->key, node->item, node->balanceFactor);
        const bool heightDecrease = removeRec(node->key, node);
        return std::pair<bool, Node*>(heightDecrease, nodeCopy);
    }
    else
    {
        return detachMinimumNode(node->leftChild);
    }
}

template < typename T1, typename T2 >
void BST<T1, T2>::displayEntriesRec(Node* node, std::ostream & os)
{
    if (isLeaf(node))
        return;
    displayEntriesRec(node->leftChild, os);
    os << node->key << ' ' << node->item << ' ' << node->balanceFactor << '\n';
    displayEntriesRec(node->rightChild, os);
}

template < typename T1, typename T2 >
void BST<T1, T2>::displayTree()
{
    displayTreeRec(root);
}

template < typename T1, typename T2 >
void BST<T1, T2>::displayTreeRec(Node* node, int depth)
{
    if (isLeaf(node))
    {
        std::cout << std::string(depth, '.') << '*' << '\n';
        return;
    }
    std::cout << std::string(depth, '.') << node->item << " - " << node->balanceFactor << '\n';
    int nextDepth = ++depth;
    displayTreeRec(node->leftChild, nextDepth);
    displayTreeRec(node->rightChild, nextDepth);
}

template < typename T1, typename T2 >
bool BST<T1, T2>::isLeaf(Node* node)
{
    return node == nullptr;
}

template < typename T1, typename T2 >
void BST<T1, T2>::deepDelete(Node* node)
{
    if (isLeaf(node))
    {
        delete node;
        return;
    }
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

template < typename T1, typename T2 >
typename BST<T1, T2>::Node* BST<T1, T2>::deepCopy(Node* original)
{
    if (isLeaf(original))
        return nullptr;

    Node* node = new Node(original->key, original->item, original->balanceFactor);
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

template < typename T1, typename T2 >
void BST<T1, T2>::rotateRight(Node* & localRoot)
{
    Node* b = localRoot;
    assert(not isLeaf(b));
    Node* a = b->leftChild;
    assert(not isLeaf(a));
    Node * beta = a->rightChild;

    localRoot = a;
    a->rightChild = b;
    b->leftChild = beta;

    b->balanceFactor = b->balanceFactor + 1 + std::max(-a->balanceFactor, 0);
    a->balanceFactor = a->balanceFactor + 1 + std::max(b->balanceFactor, 0);
}

template < typename T1, typename T2 >
void BST<T1, T2>::rotateLeft(Node* & localRoot)
{
    Node* a = localRoot;
    assert(not isLeaf(a));
    Node* b = a->rightChild;
    assert(not isLeaf(b));
    Node * beta = b->leftChild;

    localRoot = b;
    b->leftChild = a;
    a->rightChild = beta;

    a->balanceFactor = a->balanceFactor - 1 - std::max(b->balanceFactor, 0);
    b->balanceFactor = b->balanceFactor - 1 - std::max(-a->balanceFactor, 0);
}

template < typename T1, typename T2 >
bool BST<T1, T2>::rebalance(Node* & localRoot)
{
    if (localRoot->balanceFactor > 1)
    {
        if (localRoot->rightChild->balanceFactor == 1)
        {
            rotateLeft(localRoot);
            return true;
        }
        if (localRoot->rightChild->balanceFactor == 0)
        {
            rotateLeft(localRoot);
            return false;
        }
        if (localRoot->rightChild->balanceFactor == -1)
        {
            rotateRight(localRoot->rightChild);
            rotateLeft(localRoot);
            return true;
        }
    }
    else if (localRoot->balanceFactor < -1)
    {
        if (localRoot->leftChild->balanceFactor == -1)
        {
            rotateRight(localRoot);
            return true;
        }
        if (localRoot->leftChild->balanceFactor == 0)
        {
            rotateRight(localRoot);
            return false;
        }
        if (localRoot->leftChild->balanceFactor == 1)
        {
            rotateLeft(localRoot->leftChild);
            rotateRight(localRoot);
            return true;
        }
    }
    return false;
}

template < typename T1, typename T2 >
BST<T1, T2>::BST(const BST & original)
{
    this->root = deepCopy(original.root);
}

template < typename T1, typename T2 >
BST<T1, T2> & BST<T1, T2>::operator=(const BST & original)
{
    if (this == &original)
        return *this;
    deepDelete(this->root);
    this->root = deepCopy(original.root);
    return *this;
}

template < typename T1, typename T2 >
BST<T1, T2>::BST(BST<T1, T2> && original)
{
    // Is this correct? TODO
    this->root = original.root;
    original.root = nullptr;
}

template < typename T1, typename T2 >
BST<T1, T2> & BST<T1, T2>::operator=(BST<T1, T2> && original)
{
    if (this == &original)
        return *this;
    deepDelete(this->root);
    this->root = original.root;
    original.root = nullptr;
    return *this;
}

template < typename T1, typename T2 >
BST<T1, T2>::~BST()
{
    deepDelete(root);
}

template < typename T1, typename T2 >
std::ostream & operator<<(std::ostream & os, const BST<T1, T2> & bst)
{
    bst.displayEntriesRec(bst.root, os);
    return os;
}
