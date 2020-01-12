#include <functional>
#include <memory>

template < typename T1, typename T2 >
HashTable<T1, T2>::HashTable(unsigned int size, float threshold)
{
    table = make_unique<Table>();
    table->resize(size);
    entriesCount = 0;
    loadFactorThreshold = threshold;
}

template < typename T1, typename T2 >
unsigned int HashTable<T1, T2>::hash(const Key & key)
{
    return std::hash<Key>{}(key);
}

template < typename T1, typename T2 >
void HashTable<T1, T2>::insert(Key key, Item item)
{
    unsigned int index = HashTable::hash(key) % table->size();
    bool exists = false;

    for (Node & node : table->at(index))
    {
        if (node.first == key)
        {
            node.second = item;
            exists = true;
        }
    }
    if (not exists)
    {
        table->at(index).push_front(Node(key, item));
        entriesCount += 1;
        if (loadFactor() > loadFactorThreshold) resize();
    }
}

template < typename T1, typename T2 >
typename HashTable<T1, T2>::Item* HashTable<T1, T2>::lookup(Key key)
{
    unsigned int index = HashTable::hash(key) % table->size();
    
    for (Node & node : table->at(index))
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
    unsigned int index = HashTable::hash(key) % table->size();
    
    for (Node & node : table->at(index))
    {
        if (node.first == key)
        {
            table->at(index).remove(node);
            entriesCount -= 1;
        }
    }   
}

template < typename T1, typename T2 >
float HashTable<T1, T2>::loadFactor()
{
    return float(entriesCount) / float(table->size());
}

template < typename T1, typename T2 >
void HashTable<T1, T2>::resize()
{
    Table* oldTable = table;

    table = new Table();
    table->resize(oldTable->size() * 4);
    entriesCount = 0;

    for (Bucket bucket : *oldTable)
    {
        for (Node node : bucket)
        {
            insert(node.first, node.second);
        }
    }

    delete oldTable;
}
