#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include "BST.hpp"

using bstIntString = BST<int, std::string>;

BOOST_AUTO_TEST_CASE(object_creation)
{
    BOOST_CHECK_NO_THROW(bstIntString testTree);
}

BOOST_AUTO_TEST_CASE(insertion)
{
    bstIntString testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
}

BOOST_AUTO_TEST_CASE(insert_lots)
{
    bstIntString testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));
}


BOOST_AUTO_TEST_CASE(lookup_match)
{
    bstIntString testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));
    BOOST_CHECK_EQUAL(*testTree.lookup(3), "three");
}

BOOST_AUTO_TEST_CASE(lookup_no_match)
{
    bstIntString testTree;
    BOOST_CHECK_NO_THROW(testTree.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTree.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTree.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTree.insert(3, "three"));
    BOOST_CHECK_EQUAL(testTree.lookup(6), nullptr);
}

BOOST_AUTO_TEST_CASE(display_entries)
{
    bstIntString testTree;

    testTree.insert(22, "Jane");
    testTree.insert(22, "Mary");
    testTree.insert(0, "Harold");
    testTree.insert(9, "Edward");
    testTree.insert(37, "Victoria");
    testTree.insert(4, "Matilda");
    testTree.insert(26, "Oliver");
    testTree.insert(42, "Elizabeth");
    testTree.insert(19, "Henry");
    testTree.insert(4, "Stephen");
    testTree.insert(24, "James");
    testTree.insert(-1, "Edward");
    testTree.insert(31, "Anne");
    testTree.insert(23, "Elizabeth");
    testTree.insert(1, "William");
    testTree.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(std::cout << testTree);

}

BOOST_AUTO_TEST_CASE(display_tree)
{
    bstIntString testTree;

    testTree.insert(22, "Jane");
    testTree.insert(22, "Mary");
    testTree.insert(0, "Harold");
    testTree.insert(9, "Edward");
    testTree.insert(37, "Victoria");
    testTree.insert(4, "Matilda");
    testTree.insert(26, "Oliver");
    testTree.insert(42, "Elizabeth");
    testTree.insert(19, "Henry");
    testTree.insert(4, "Stephen");
    testTree.insert(24, "James");
    testTree.insert(-1, "Edward");
    testTree.insert(31, "Anne");
    testTree.insert(23, "Elizabeth");
    testTree.insert(1, "William");
    testTree.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(testTree.displayTree());

}

BOOST_AUTO_TEST_CASE(delete_leaf)
{
    bstIntString testTree;

    testTree.insert(22, "Jane");
    testTree.insert(22, "Mary");
    testTree.insert(0, "Harold");
    testTree.insert(9, "Edward");
    testTree.insert(37, "Victoria");
    testTree.insert(4, "Matilda");
    testTree.insert(26, "Oliver");
    testTree.insert(42, "Elizabeth");
    testTree.insert(19, "Henry");
    testTree.insert(4, "Stephen");
    testTree.insert(24, "James");
    testTree.insert(-1, "Edward");
    testTree.insert(31, "Anne");
    testTree.insert(23, "Elizabeth");
    testTree.insert(1, "William");
    testTree.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(testTree.remove(31));

    BOOST_CHECK_EQUAL(testTree.lookup(31), nullptr);

}

BOOST_AUTO_TEST_CASE(delete_with_one_child)
{
    bstIntString testTree;

    testTree.insert(22, "Jane");
    testTree.insert(22, "Mary");
    testTree.insert(0, "Harold");
    testTree.insert(9, "Edward");
    testTree.insert(37, "Victoria");
    testTree.insert(4, "Matilda");
    testTree.insert(26, "Oliver");
    testTree.insert(42, "Elizabeth");
    testTree.insert(19, "Henry");
    testTree.insert(4, "Stephen");
    testTree.insert(24, "James");
    testTree.insert(-1, "Edward");
    testTree.insert(31, "Anne");
    testTree.insert(23, "Elizabeth");
    testTree.insert(1, "William");
    testTree.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(testTree.remove(4));

    BOOST_CHECK_EQUAL(testTree.lookup(4), nullptr);

    // TODO: Test child has been moved to correct place

}

BOOST_AUTO_TEST_CASE(delete_with_two_children)
{
    bstIntString testTree;

    testTree.insert(22, "Jane");
    testTree.insert(22, "Mary");
    testTree.insert(0, "Harold");
    testTree.insert(9, "Edward");
    testTree.insert(37, "Victoria");
    testTree.insert(4, "Matilda");
    testTree.insert(26, "Oliver");
    testTree.insert(42, "Elizabeth");
    testTree.insert(19, "Henry");
    testTree.insert(4, "Stephen");
    testTree.insert(24, "James");
    testTree.insert(-1, "Edward");
    testTree.insert(31, "Anne");
    testTree.insert(23, "Elizabeth");
    testTree.insert(1, "William");
    testTree.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(testTree.remove(0));

    BOOST_CHECK_EQUAL(testTree.lookup(0), nullptr);

    // TODO: Test child has been moved to correct place

}

BOOST_AUTO_TEST_CASE(deep_copy_constructor)
{
    bstIntString testTree;
    testTree.insert(22, "Jane");
    bstIntString testTree2 = testTree;
    testTree.insert(2, "Will");

    BOOST_CHECK_EQUAL(testTree2.lookup(2), nullptr);

}

BOOST_AUTO_TEST_CASE(deep_copy_assignment)
{
    bstIntString testTree;
    bstIntString testTree2;
    testTree.insert(22, "Jane");
    testTree2 = testTree;
    testTree.insert(2, "Will");

    BOOST_CHECK_EQUAL(testTree2.lookup(2), nullptr);

}

BOOST_AUTO_TEST_CASE(move_constructor)
{
    bstIntString testTree;
    testTree.insert(22, "Jane");
    bstIntString testTree2 = std::move(testTree);
    testTree.insert(2, "Will");

    BOOST_CHECK_EQUAL(testTree.lookup(22), nullptr);
    BOOST_CHECK_EQUAL(testTree2.lookup(2), nullptr);

}

BOOST_AUTO_TEST_CASE(move_assignment)
{
    bstIntString testTree;
    bstIntString testTree2;
    testTree.insert(22, "Jane");
    testTree2 = std::move(testTree);
    testTree.insert(2, "Will");

    BOOST_CHECK_EQUAL(testTree.lookup(22), nullptr);
    BOOST_CHECK_EQUAL(testTree2.lookup(2), nullptr);

}

BOOST_AUTO_TEST_CASE(template_string_int)
{
    BST<std::string, int> testTree;
    testTree.insert("theAnswer", 42);

    BOOST_CHECK_EQUAL(*testTree.lookup("theAnswer"), 42);
    BOOST_CHECK_EQUAL(testTree.lookup("nothing"), nullptr);

}

BOOST_AUTO_TEST_CASE(rebalance)
{
    bstIntString testTree;

    testTree.insert(1, "Jane");
    testTree.insert(2, "Harry");
    testTree.insert(3, "Bob");
    testTree.insert(4, "Paul");
    testTree.insert(5, "Greg");

    testTree.displayTree();
    testTree.testRebalance();
    testTree.displayTree();

}
