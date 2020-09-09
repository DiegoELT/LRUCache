#include <iostream>

template <class KeyType, class DataType>
class Node
{
  private:
    KeyType key;
    DataType data; 
  public:
    Node(KeyType _key, DataType _data)
    {
      key = _key;
      data = _data;
    }
    KeyType getKey()
    {
      return key;
    }
    DataType getData()
    {
      return data;
    };
};