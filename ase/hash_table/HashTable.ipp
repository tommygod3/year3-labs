template < typename T1, typename T2 >
unsigned int HashTable<T1, T2>::hash(const Key & key)
{
    return key.length();
}
