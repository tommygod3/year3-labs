#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include "HashTable.hpp"

using stringTable = HashTable<std::string, std::string>;

BOOST_AUTO_TEST_CASE(test_insert)
{
    stringTable testTable = stringTable();
    BOOST_CHECK_NO_THROW(testTable.insert("Hello", "world"));
}

BOOST_AUTO_TEST_CASE(test_lookup)
{
    stringTable testTable = stringTable();
    testTable.insert("Hello", "world");
    BOOST_CHECK_EQUAL(*testTable.lookup("Hello"), "world");
}

BOOST_AUTO_TEST_CASE(test_remove)
{
    stringTable testTable = stringTable();
    testTable.insert("Hello", "world");
    BOOST_CHECK_NO_THROW(testTable.remove("Hello"));
}
