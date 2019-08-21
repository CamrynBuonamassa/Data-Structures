#include <iostream>
#include <string>
#include "List.h"

List::List(){
  head = nullptr;
  dummy = new Node("dummy", head);
  size = 0;
}

List::~List(){
  std::cout << "In the destructor\n";
  if (dummy != nullptr){
    Node *t,*t2;
    t=dummy->getNext();
    while (t!=nullptr){
      t2=t;
      t=t->getNext();
      delete t2;
    }
    delete dummy;
  }
  size = 0;
}

int List::getSize(){
  return size;
}

void List::insert(std::string data){
  Node *t = new Node(data,nullptr);
  if (head==nullptr){
    head=t;
  }
  else{
    t->setNext(head);
    head = t;
    dummy->setNext(head);
  }
  size++;
}

std::string List::getDebugString(){
  std::string s = "";
  Node *t = dummy; //change back to head
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}

void List::push_back(std::string data){ // inserts at the end of the vector
  Node *t = new Node(data,nullptr);
  Node *temp;
  if(head==nullptr){
    head = t;
  }
  else{
    temp = head;
    while(temp->getNext()!=nullptr){
      temp = temp->getNext();
    } 
    temp->setNext(t);
  }
  size++;
}

std::string List::at(int i){ // returns the element at a location
  Node *temp;
  temp = head;
  int index = 0;
  if(i>=size){
    return "out of range";
  }
  else if(index==i){
    return temp->getData();
  }
  else{
    while(index!=i){
      index++;
      temp = temp->getNext(); 
    }
  return temp->getData();
  }
}

void List::insert(int i, std::string data){ // inserts string at location
  Node *insert_node = new Node;
  Node *temp;
  temp = head;
  int index = 0;
  while(index<i){
      index++;
      temp = temp->getNext(); 
  }
  if(temp==nullptr){
    insert_node->setData(data);
    insert_node->setNext(nullptr);
    }
  else {
    insert_node->setData(data);
    insert_node->setNext(temp->getNext());
  }
  size++;
}

void List::remove(int i){ // removes the element at location i
  int index = -1;
  if(head==nullptr){
    return;
  }
  else{
    Node *temp = new Node;
    Node *remove;
    temp = dummy;
    while(index<i-1){
      index++;
      temp = temp->getNext();
    }
    remove = temp->getNext();
    temp->setNext(remove->getNext());
    delete remove;
    size--;
  }
}

std::string &List::operator[](int i){ // overloaded square brackets
  Node *temp;
  temp = head;
  std::string ref;
  int index = 0;
  if(index==i){
    ref = temp->getData();
    return ref;
  }
  else{
    while(index<i){
      index++;
      temp = temp->getNext(); 
    }
    ref = temp->getData();
    return ref;
  }
}
