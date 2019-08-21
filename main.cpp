#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->getDebugString();
  l->insert("one");
  l->insert("two");
  l->insert("three");
  l->insert("four");
  l->push_back("zero");
  l->remove(0);
  std::cout << l->getDebugString();
  std::cout << "Element at 4: ";
  std::cout << l->at(4) << std::endl;
  delete l;

  List l2;
  l2.insert("a");
  l2.insert("b");
  l2.insert("c");
  l2.insert("d");
  std::cout << l2.getDebugString();
  std::cout << "Element at 2: ";
  std::string ref = l2.operator[](2);
  std::cout << ref << std::endl;
}
