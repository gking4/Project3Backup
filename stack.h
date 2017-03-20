#ifndef STACK_H
#define STACK_H

#include "list.h"

template <typename T>

class Stack
{
  private:
    List<T> alist;
    int stack_size;
  public:
    Stack<T>(): alist(List<T>()), stack_size(0) {};
    ~Stack<T>() {alist.clear();}
    bool empty() {if(alist.size() == 0) {return true;} else {return false;}}
    int size() {return alist.size();}
    void push(T item) {alist.insert(item);}
    void pop() {alist.remove();}
    T top(){return alist.front();}
};

#endif
