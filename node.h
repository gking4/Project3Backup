#include <iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
  Node* next;
  T value;
  Node(): value(T()), next(NULL){};
  Node(T item, Node* ptr): value(item), next(ptr) {};
};

#endif
