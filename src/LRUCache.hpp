#include "SimpleList.hpp"
#include <unordered_map>
#include <list>

template <class KeyType, class DataType>
class Cache
{
  protected:
    std::unordered_map<KeyType, Node<KeyType, DataType>*> hashMap;
    DLList<KeyType, DataType> queue; 
    int maxSize;
    virtual void insertCriteria() = 0;
    virtual void cacheCriteria(KeyType operatedKey) = 0;
  public:
    Cache(int cacheSize)
    {
      maxSize = cacheSize;
    }
    void insertKeyValuePair(KeyType newKey, DataType newData)
    {
      Node<KeyType, DataType> *newNode = new Node<KeyType, DataType>(newKey, newData);
      if (hashMap.find(newKey) != hashMap.end())
      {
        hashMap[newKey] -> data = newData;
        cacheCriteria(newKey);
      }
      else
      {
        hashMap[newKey] = newNode;
        queue.insert(newNode);
        insertCriteria();
      }
    }
    DataType * getValueFromKey(KeyType keyToSearch)
    {
      if (hashMap.find(keyToSearch) == hashMap.end())
      {
        return nullptr;
      }
      else
      {
        cacheCriteria(keyToSearch);
        return &(hashMap[keyToSearch] -> data);
      }
    }
    KeyType getMostRecentKey()
    {
      return queue.getTail() -> key;
    }
    void debugFunc()
    {
      queue.debugPrint();
    }
};

template <class KeyType, class DataType>
class LRUCache : public Cache<KeyType, DataType>
{
  void insertCriteria()
  {
    if (Cache<KeyType, DataType>::queue.getSize() > Cache<KeyType, DataType>::maxSize)
    {
      KeyType keyToDelete = Cache<KeyType, DataType>::queue.getHead() -> key;
      Cache<KeyType, DataType>::queue.popFront();
      Cache<KeyType, DataType>::hashMap.erase(keyToDelete);
    } 
  }
  void cacheCriteria(KeyType operatedKey)
  {
    Node<KeyType, DataType> * searchedNode = Cache<KeyType, DataType>::hashMap[operatedKey];
    Node<KeyType, DataType> * cloneNode = new Node<KeyType, DataType>(searchedNode -> key, searchedNode -> data);
    Cache<KeyType, DataType>::queue.erase(searchedNode);
    Cache<KeyType, DataType>::queue.insert(cloneNode);
    Cache<KeyType, DataType>::hashMap[operatedKey] = cloneNode;
  }
  public: 
    LRUCache(int cacheSize) : Cache<KeyType, DataType>(cacheSize) {}

};

template <class KeyType, class DataType>
class FIFOCache : public Cache<KeyType, DataType>
{
  void insertCriteria() // Same insert criteria as the other one.
  {
    if (Cache<KeyType, DataType>::queue.getSize() > Cache<KeyType, DataType>::maxSize)
    {
      KeyType keyToDelete = Cache<KeyType, DataType>::queue.getHead() -> key;
      Cache<KeyType, DataType>::queue.popFront();
      Cache<KeyType, DataType>::hashMap.erase(keyToDelete);
    } 
  }
  void cacheCriteria(KeyType operatedKey)
  {
    return; // No cache criteria.
  }
};