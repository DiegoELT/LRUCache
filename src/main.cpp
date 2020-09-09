#include "Node.hpp"

int main()
{
  Node<int, char> *sampleNode = new Node<int, char>(3, 'c');
  std::cout << sampleNode -> getData();
}