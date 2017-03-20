#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>

using namespace std;

template <typename T>

class List
{
  private:
    Node<T>* head = NULL;
    int length;
  public:
    List<T>(): head(NULL), length(0) {};
    List<T>(const List<T> &ref);
    ~List<T>();
    T front();
    void copy(const List<T> &rhs);
    List<T>& operator=(const List<T> &rhs);
    void insert(T item);
    bool remove();
    void clear();
    int size();
};

#endif
