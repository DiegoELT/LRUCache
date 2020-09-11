#include "LRUCache.hpp"

int main()
{
  LRUCache<std::string, int> *sampleCache = new LRUCache<std::string, int>(3);

  sampleCache -> insertKeyValuePair("b",2);
  sampleCache -> insertKeyValuePair("a",1);
  sampleCache -> insertKeyValuePair("c",3);
  std::cout << "The most recently used key was: " << sampleCache -> getMostRecentKey() << "\n";
  std::cout << "The value from key 'a' is: " << *(sampleCache -> getValueFromKey("a")) << "\n";
  std::cout << "The most recently used key was: " << sampleCache -> getMostRecentKey() << "\n";
  sampleCache -> insertKeyValuePair("d",4);
  std::cout << "The value from key 'b' is: \n";
  sampleCache -> getValueFromKey("b");
  sampleCache -> insertKeyValuePair("a",5);
  std::cout << "The value from key 'a' is: " << *(sampleCache -> getValueFromKey("a")) << "\n";
}