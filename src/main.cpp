#include "LRUCache.hpp"

int main()
{
  Node<int, char> *sampleNode = new Node<int, char>(3, 'c');
  // Cache<int, char> *sampleCache = new Cache<int, char>();
  // sampleCache -> insertKeyValuePair(2, 'b');
  std::cout << sampleNode -> getData();
}