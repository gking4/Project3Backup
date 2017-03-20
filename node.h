#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>

class Node
{
  public:
    Node<T>(): value(T()), next(NULL) {};
    Node<T>(T item, Node* ptr): value(item), next(ptr) {};
    Node* next;
    T value;
};

#endif
