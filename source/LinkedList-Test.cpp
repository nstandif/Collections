//
//  Project   : Collections I
//  File      : LinkedList-Test.cpp
//  Desc.     : Unit Tests for LinkedList
//  Author    : Nathan Standiford <ns@byu.edu>
//
#include "LinkedList-Test.h"
#include "UnitTest.h"
#include <iostream>
using namespace std;


void addData(LinkedList & l) {
  for(int i = 0; i < testDataSize; i++)
    l.Insert(testData[i],NULL);
}

bool LinkedList::Test(ostream & os) {
  
  bool success = true;  
  cout << "size" << endl;
  LinkedList l; // initialize
  TEST(l.GetSize() == 0);
  
  l.Insert(testData[0],NULL);
  TEST(l.GetSize() == 1);
  
  cout << "first and last init" << endl;
  LLNode * firstNode = l.GetFirst();
  LLNode * lastNode  = l.GetLast();
  TEST(firstNode == lastNode);
  
  l.Insert(testData[1],firstNode);
  lastNode = l.GetLast();
  TEST(firstNode != lastNode);
  TEST(lastNode->prev == firstNode);
  TEST(firstNode->next == lastNode);
  
  
  l.Insert("stuff",NULL);
  TEST(l.first->value == "stuff");

  cout << "find" << endl;
  TEST(l.Find("stuff",NULL));
  TEST(!l.Find("stuff",l.first));
  TEST(!l.Find("stuff",l.last));

  l.Clear();
  TEST(l.GetSize() == 0);
  TEST(!l.first);
  TEST(!l.last);
  addData(l);
  TEST(l.GetSize() == testDataSize);
  TEST(!l.IsEmpty());
  l.Clear();

  TEST(l.GetFirst() == NULL);
  TEST(l.GetLast() == NULL);
  TEST(l.IsEmpty());

  LinkedList l2;

  addData(l2);  
  LinkedList l0;
  l = l0 = l2;
  
  TEST(l.GetSize() == testDataSize);
  TEST(l.GetFirst()->value == l2.GetFirst()->value);
  
  l0 = l = l;
  TEST(l0.GetFirst()->value == l.GetFirst()->value
       && l.GetFirst()->value == l2.GetFirst()->value);

  LLNode * n = l.first;
  LLNode * next = n->next;
  l.Remove(n);
  TEST(l.first == next);
  TEST(!next->prev);
  
  n = l.last;
  LLNode * prev = n->prev;
  l.Remove(n);
  TEST(l.last == prev);
  TEST(!prev->next);
  TEST(l.size < testDataSize);

  l.Clear();
  l.Insert(testData[0],NULL);
  n = l.last;
  l.Remove(n);
  TEST(l.IsEmpty());
   
  return success;
}

int main() {
  bool success = true;

  if(!LinkedList::Test(cout))
    success = false;

  if(success) {
    cout << "Tests Succeeded!" << endl;
  } else {
    cout << "Tests Failed!" << endl;
  }

  return 0;
}
