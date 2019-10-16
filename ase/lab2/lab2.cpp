#include "BST.hpp"

int main ()
{
    BST test;

    test.insert(1, "h");

    std::cout << *test.lookup(1);
    
    return 0;
}