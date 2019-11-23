#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include "HashTable.hpp"

using intStringTable = HashTable<int, std::string>;

BOOST_AUTO_TEST_CASE(test_insert)
{
    intStringTable testTable = intStringTable();
    BOOST_CHECK_NO_THROW(testTable.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTable.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTable.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTable.insert(3, "three"));
}

BOOST_AUTO_TEST_CASE(test_lookup)
{
    intStringTable testTable = intStringTable();
    BOOST_CHECK_NO_THROW(testTable.insert(10, "ten"));
    BOOST_CHECK_NO_THROW(testTable.insert(5, "five"));
    BOOST_CHECK_NO_THROW(testTable.insert(1, "one"));
    BOOST_CHECK_NO_THROW(testTable.insert(3, "three"));
    BOOST_CHECK_EQUAL(*testTable.lookup(3), "three");
}

BOOST_AUTO_TEST_CASE(test_remove)
{
    intStringTable testTable = intStringTable();

    testTable.insert(22, "Jane");
    testTable.insert(22, "Mary");
    testTable.insert(0, "Harold");
    testTable.insert(9, "Edward");
    testTable.insert(37, "Victoria");
    testTable.insert(4, "Matilda");
    testTable.insert(26, "Oliver");
    testTable.insert(42, "Elizabeth");
    testTable.insert(19, "Henry");
    testTable.insert(4, "Stephen");
    testTable.insert(24, "James");
    testTable.insert(-1, "Edward");
    testTable.insert(31, "Anne");
    testTable.insert(23, "Elizabeth");
    testTable.insert(1, "William");
    testTable.insert(26, "Charles");

    BOOST_CHECK_NO_THROW(testTable.remove(31));

    BOOST_CHECK_EQUAL(testTable.lookup(31), nullptr);
}

BOOST_AUTO_TEST_CASE(test_resize)
{
    intStringTable testTable = intStringTable();

    for (unsigned int i = 0; i < 10000; i++)
    {
        BOOST_CHECK_NO_THROW(testTable.insert(i, "test"));
    }
}
