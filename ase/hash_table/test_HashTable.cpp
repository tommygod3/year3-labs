#define BOOST_TEST_MODULE test_BST
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include <string>
#include "HashTable.hpp"

using stringTable = HashTable<std::string, std::string>;

BOOST_AUTO_TEST_CASE(hash)
{
    BOOST_CHECK_EQUAL(stringTable::hash("hello"), 2);

}