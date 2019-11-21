#include <string>
#include <vector>
#include <forward_list>

template < typename T1, typename T2 >
class HashTable
{
    public:
        using Key = T1;
        using Item = T2;

        HashTable(unsigned int size = 100);

        void insert(Key, Item);
        Item* lookup(Key);
        void remove(Key);

    
    private:
        using Table = std::vector<std::forward_list<std::pair<Key, Item>>>;
        // Converts the Key into an integer to then be modulo
        static unsigned int hash(const Key &);
        Table table;

};

#include "HashTable.ipp"