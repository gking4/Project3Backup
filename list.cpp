#include "list.h"

//Copy constructor that calls member function copy
template<typename T>
List<T>::List(const List&rhs)
{
  this->copy(rhs);
}//List(const List&rhs)

//destructor of the class
//this function is called when List object is destroyed
template<typename T>
List<T>::~List(){
        Node<T> *ptr = head;
        while(ptr != NULL){
                Node<T> *temp = ptr;
                ptr = ptr->next;
                delete temp;//deletes Node<T> object

        }//while
}//destructor

//copies another list object
template<typename T>
void List<T>::copy(const List &rhs)
{
  Node<T>* rhs_cur = rhs.head;
  Node<T>* cur = this->head;
  while(rhs_cur != NULL)
  {
    Node<T>* temp = new Node<T>(rhs_cur->value, NULL);
    if(cur == NULL)
    {
      head = temp;

    }//if
    else
    {
      cur->next = temp;
    }//else
      cur = temp;
      rhs_cur = rhs_cur->next;
      length++;
  }//while
}//copy

//Deallocates space taken up by items in the list, sets head to NULL
template<typename T>
void List<T>::clear()
{
  if(head == NULL)
  {
    return;
  }//if
  Node<T> * cur = head;
  while(cur != NULL)
  {
    Node<T> * temp = cur->next;
    delete cur;
    length--;
    cur = temp;
  }//while
  head = NULL;
}//clear

//overloads the = operator to compare two lists
template<typename T>
List<T>& List<T>::operator=(const List & rhs)
{
  if(head != NULL)
  {
    clear();
    this->copy(rhs);
    return *this;
  }

}//operator=

//inserts a Node<T> object into a list in front of the list
template<typename T>
void List<T>::insert(T item){
        Node<T> *ptr_to_Node = new Node<T>(item, head);
        head = ptr_to_Node;
        ptr_to_Node = NULL;
        length++;
}//insert

//removes the front of the list
template<typename T>
bool List<T>::remove(){
        if(length == 0)
                return false;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
        return true;
}//remove()

//finds and returns the size of a list
template<typename T>
int List<T>::size()
{
  return length;
}//size()

//returns the front value
template<typename T>
T List<T>::front()
{
  if(head != NULL)
  {
  return head->value;
  }
}//front
