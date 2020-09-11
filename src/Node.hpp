#include <iostream>

template <class KeyType, class DataType>
struct Node
{
    KeyType key;
    DataType data; 
    Node<KeyType, DataType> * prev = nullptr; 
    Node<KeyType, DataType> * next = nullptr; 
    Node(KeyType _key, DataType _data)
    {
      key = _key;
      data = _data;
    }
};