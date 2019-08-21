#include <iostream>

#include <string>
#include "Node.h"

class List{
private:
  Node *dummy;
  Node *head;
  int size;
public:
  List();
  ~List();
  void insert(std::string data);
  std::string getDebugString();
  int getSize();
  void push_back(std::string data); // inserts at the end of the vector
  std::string at(int i); // returns the element at a location
  void insert(int i, std::string data); // inserts string at location
  void remove(int i); // removes the element at location i
  std::string &operator[](int); // overloaded square brackets
};
