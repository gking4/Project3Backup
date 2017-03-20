#include "list.h"

template <typename T>
bool List<T>::remove(){ //removes first list in the list
        if(length == 0)
                return false;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()

template <typename T>
void List<T>::clear()  //clears the enitre list of nodes
{
  if(length == 0) {return;}
  else if (length == 1)
  {
    delete head;
    head = NULL;
    length = 0;
  }
  else
  {
    for(int t = length; t > 0; t--) 
    {
      remove();
    }
    length = 0;
  }
}

template <typename T>
void List<T>::insert(T item){
       Node<T>* ptr_to_node = new Node<T>(item, head);
       head = ptr_to_node;
       ptr_to_node = NULL;
       length++;
}//insert

template <typename T>
void List<T>::copy(const List<T> &rhs) //copies a list
{
  Node<T>* rhs_cur = rhs.head;
  Node<T>* cur = this->head;
  while(rhs_cur != NULL)
  {
    Node<T>* temp = new Node<T>(rhs_cur->value, NULL);
    if(cur == NULL)
    {
      head = temp;
    }
    else
    {
      cur->next = temp;
    }
    cur = temp;
    length++;
    rhs_cur = rhs_cur->next;
  }
}


template <typename T>
List<T>::List(const List<T> &rhs) //copy constructor
{
  length = 0;
  this->copy(rhs); 
}//copy constructor

template <typename T>
int List<T>::size()//returns the size
{
  return length;
}//size

template <typename T>
T List<T>::front()//accesses the front value
{
  if(length == 0)
  {
    cerr << "Error: Invalid expression." << endl;
  }
  if(head != NULL)
  {
    return head->value;
  }
}//front

//destructor of the class
template <typename T>
List<T>::~List(){
        Node<T> *ptr = head;
        while(ptr != NULL){
                Node<T> *temp = ptr;
                ptr = ptr->next;
                delete temp;

        }//while
}//destructor
