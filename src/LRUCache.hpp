#include "Node.hpp"
#include <unordered_map>
#include <list>

template <class KeyType, class DataType>
class Cache
{
  private:
    std::unordered_map<KeyType, Node<KeyType, DataType>*> hashMap;
    std::list<Node<KeyType, DataType>> queue; 
    int maxSize;
    //virtual void insertCriteria() = 0;
    //virtual void cacheCriteria(KeyType operatedKey);
  public:

    void insertKeyValuePair(KeyType newKey, DataType newData)
    {
      Node<KeyType, DataType> *newNode = new Node<KeyType, DataType>(newKey, newData);
      hashMap[newKey] = newNode;
      queue.push_back(*newNode);
      //insertCriteria();
    }
    DataType * getValueFromKey(KeyType keyToSearch)
    {
      if (hashMap.find(keyToSearch) == hashMap.end())
        return nullptr;
      else
      {
        //cacheCriteria(keyToSearch);
        return &(hashMap[keyToSearch].getData());
      }
    }
};

