#include <string>

template < typename T1, typename T2 >
class HashTable
{
    public:
        using Key = T1;
        using Item = T2;

        HashTable() = default;

        void insert(Key, Item);
        Item* lookup(Key);
        void remove(Key);
    
    //private:
        // Converts the Key into an integer to then be modulo
        static unsigned int hash(const Key &);

};

#include "HashTable.ipp"