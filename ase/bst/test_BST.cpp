#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "BST.hpp"

BOOST_AUTO_TEST_CASE(object_creation)
{
    BOOST_CHECK_NO_THROW(BST testTree);
}

BOOST_AUTO_TEST_CASE(insertion)
{
    BST testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
}

BOOST_AUTO_TEST_CASE(insert_lots)
{
    BST testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));
}


BOOST_AUTO_TEST_CASE(lookup)
{
    BST testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));
    BOOST_CHECK_EQUAL(*testTree.lookup(3), "three");
}
