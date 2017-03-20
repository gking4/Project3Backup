#include "list.h"

#ifndef STACK_H
#define STACK_H

template<typename T>

class Stack
{
private:
  List<T> alist;
public:
  Stack(): alist(List<T>()) {};
  ~Stack() {alist.clear();}
  bool empty() {if(alist.size() == 0){return true;} else{return false;}}
  T top(){return alist.front();}
  void pop(){alist.remove();}
  void push(T item){alist.insert(item);}
  int size(){return alist.size();}
};

#endif
