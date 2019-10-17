#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "BST.hpp"

BOOST_AUTO_TEST_CASE(test_BST)
{
    // Create Binary Search Tree
    BST testTree;
    // Ensure inserting values at different points in the tree does not throw
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));

    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));

    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));

    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));

    // Setup and test that lookup works
    std::string* correctAnswer = new std::string("three");
    BOOST_CHECK_EQUAL(*testTree.lookup(3), *correctAnswer);
    delete correctAnswer;
}
