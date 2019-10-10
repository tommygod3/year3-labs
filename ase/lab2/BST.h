#include <iostream>

class BinarySearchTree
{
    public:
        using Key = int;
        using Item = std::string;

        void insert(Key, Item);
        Item* lookup(Key);
};
