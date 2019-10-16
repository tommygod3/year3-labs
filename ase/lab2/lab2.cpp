#include "BST.hpp"

int main ()
{
    BST test;

    test.insert(5, "first");

    std::cout << *test.lookup(5);

    test.insert(2, "second");
    test.insert(7, "third");

    test.insert(1, "fourth");
    test.insert(4, "fifth");

    test.insert(3, "sixth");

    std::cout << *test.lookup(3);
    
    return 0;
}