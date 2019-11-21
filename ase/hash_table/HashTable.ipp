#include <functional>

template < typename T1, typename T2 >
HashTable<T1, T2>::HashTable(unsigned int size)
{
    this->table.resize(size);
}

template < typename T1, typename T2 >
unsigned int HashTable<T1, T2>::hash(const Key & key)
{
    return std::hash<Key>{}(key);
}

template < typename T1, typename T2 >
void HashTable<T1, T2>::insert(Key key, Item item)
{
    unsigned int index = HashTable::hash(key) % table.size();
    bool exists = false;

    for (auto node : table[index])
    {
        if (node.first == key)
        {
            node.second = item;
            exists = true;
        }
    }
    if (not exists)
    {
        table[index].push_front(std::pair<Key, Item>(key, item));
    }
}

template < typename T1, typename T2 >
typename HashTable<T1, T2>::Item* HashTable<T1, T2>::lookup(Key key)
{
    unsigned int index = HashTable::hash(key) % table.size();
    
    for (std::pair<Key, Item> & node : table[index])
    {
        if (node.first == key)
        {
            return &node.second;
        }
    }

    return nullptr;
}

template < typename T1, typename T2 >
void HashTable<T1, T2>::remove(Key key)
{
    unsigned int index = HashTable::hash(key) % table.size();
    
    for (auto node : table[index])
    {
        if (node.first == key)
        {
            table[index].remove(node);
        }
    }   
}
