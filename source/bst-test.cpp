//
//  Project : Collections I
//  File    : bst-test.cpp
//  Desc.   : test-perfoming logic for bst
//  Author  : Nathan Standiford <ns@byu.edu>
//

#include "bst-test.h"
#include "UnitTest.h"
#include <string>
#include <iostream>
using namespace std;

void printTree(const BSTNode * t) {
  cout << t->GetValue() << endl;
  if(t->GetLeft()) {
    cout << "Left of " << t->GetValue() << ":" << endl;
    printTree(t->GetLeft());
  }
  if(t->GetRight()) {
    cout << "Right of " << t->GetValue() << ":" << endl;
    printTree(t->GetRight()); 
  }
}

void printTest(const string & t) {
  cout << "testing "
       << t
       << endl;
}

bool BST::Test(ostream & os) {
  bool success = true;
  printTest("GetSize()");
  BST t;
  cout << t.size << endl;
  TEST(t.GetSize() == 0);
  t.Insert("rock");
  TEST(t.GetSize() == 1);  
  printTest("Clear()");
  t.Clear();
  TEST(t.GetSize() == 0);
  
  printTest("IsEmpty()");
  TEST(t.IsEmpty());
  t.Insert("bad");
  TEST(!t.IsEmpty());
  t.Clear();
  
  printTest("GetRoot()");
  TEST(t.root == t.GetRoot());

  printTest("Insert()");
  for(int i = 0; i < TEST_DATA_SIZE; i++) {
    t.Insert(testData[i]);
  }

  TEST(t.GetSize() == TEST_DATA_SIZE);
  TEST(t.GetRoot()->GetValue() == expData[ALPHA]);
  TEST(t.GetRoot()->GetRight()->GetValue() == expData[BETA]);
  TEST(!t.GetRoot()->GetLeft());

  // BSTNode * n = t.GetRoot()->GetRight()->GetLeft();
  TEST(t.root->right->right);
  if(success)
    TEST(t.root->right->right->value == expData[GAMMA]);
  else
    printTree(t.GetRoot());
  
  printTest("Find()");
  BSTNode * n;
  for(int i = 0; i < TEST_DATA_SIZE; i++) {
    n = t.Find(testData[i]);
    TEST(n != NULL);
  }
  const string s = "bogus";
  n = t.Find(s);
  TEST(n == NULL);

  BST * t2 = new BST(t);
  TEST(t2->size == t.size);
  t2->root->value = "fred";
  TEST(t2->root->value != t.root->value);
  
  BST t1;
  t1 = *t2 = t;
  TEST(t1.GetRoot()->value == t.GetRoot()->value);
  
  return success;
}

int main() {
  bool result = BST::Test(cout);
  if(result) {
    cout << "Tests Succeeded!" << endl;
  } else { 
    cout << "Tests Failed!" << endl;
  }
  return 0;
}
