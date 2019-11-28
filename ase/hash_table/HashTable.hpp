#include <string>
#include <vector>
#include <forward_list>

template < typename T1, typename T2 >
class HashTable
{
    public:
        using Key = T1;
        using Item = T2;

        HashTable(unsigned int size = 100, float threshold = 0.7);

        void insert(Key, Item);
        Item* lookup(Key);
        void remove(Key);

    
    private:
        using Node = std::pair<Key, Item>;
        using Bucket = std::forward_list<Node>;
        using Table = std::vector<Bucket>;
        // Converts the Key into an integer to then be modulo
        static unsigned int hash(const Key &);
        // TODO: Add unique ptr
        Table* table;
        unsigned int entriesCount;
        float loadFactor();
        float loadFactorThreshold;
        void resize();
};

#include "HashTable.ipp"