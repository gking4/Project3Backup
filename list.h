#include "node.h"

#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
private:
  Node<T>* head = NULL;
  int length;
public:
  List<T>(): head(NULL), length(0){};
  List<T>(const List & rhs);
  ~List();
  void copy(const List<T> & rhs);
  void clear();
  List<T>& operator=(const List<T> &rhs);
  void insert(T item);
  bool remove();
  int size();
  T front();

};

#endif
