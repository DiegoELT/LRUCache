#include "Node.hpp"

template <class KeyType, class DataType>
class DLList
{
  private: 
    Node<KeyType, DataType> * head = nullptr;
    Node<KeyType, DataType> * tail = nullptr;
    int size = 0;
  public:
    void insert(Node<KeyType, DataType> * newNode)
    {
      if(!size)
        head = newNode;
      else
        tail -> next = newNode;
      newNode -> prev = tail;
      tail = newNode;
      size++;
    }
    void popFront()
    {
      Node<KeyType, DataType> * tempHead = head;
      head = tempHead -> next;
      delete tempHead;
      head -> prev = nullptr;
      size--;
    }
    void erase(Node<KeyType, DataType> * erasedNode)
    {
      if (erasedNode == head)
        popFront();
      else
      {
        if(erasedNode == tail)
        {
          Node<KeyType, DataType> * tempTail = tail;
          tail = tempTail -> prev;
          delete tempTail;
          tail -> next = nullptr;
        }
        else
        {
          (erasedNode -> prev) -> next = erasedNode -> next;
          (erasedNode -> next) -> prev = erasedNode -> prev;
          delete erasedNode;
        }
      }
      size--;
    }
    int getSize()
    {
      return size;
    }
    Node<KeyType, DataType> * getHead()
    {
      return head;
    }
    Node<KeyType, DataType> * getTail()
    {
      return tail;
    }
    void debugPrint()
    {
      Node<KeyType, DataType> * tempNode = head;
      while(tempNode != nullptr)
      {
        std::cout << tempNode -> data << "\n";
        tempNode = tempNode -> next;
      }
    }
};