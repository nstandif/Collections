//
//  Project : Collections I
//  File    : BST.cpp
//  Desc.   : binary search tree in C++
//  Author  : Nathan Standiford <ns@byu.edu>
//
#include "BST.h"
#include <string>
using namespace std;

BST::BST() : root(NULL),size(0) {

}

BST::BST(const BST & other) {
  root = NULL;
  size = 0;
  copy(other);
}

BST::~BST() {
  ClearR(root);
}

void BST::ClearR(BSTNode * n) {
  if(n) {
    if(n->left)
      ClearR(n->left);
    if(n->right)
      ClearR(n->right);
    delete n;
  }
}


void BST::copy(const BST & other) {
  rcopy(other.GetRoot());
}

void BST::rcopy(const BSTNode * n) {
  if(n == NULL)
    return;
   
  Insert(n->GetValue());
  
  if(n->GetLeft())
    Insert(n->GetLeft()->GetValue());
  
  if(n->GetRight())
    Insert(n->GetRight()->GetValue());
  rcopy(n->GetLeft());
  rcopy(n->GetRight());
}


BST& BST::operator= (const BST & other) {
  if(this != &other) {
    Clear();
    copy(other);
  }
  return *this;
}

BSTNode * BST::GetRoot()const {
  return this->root;
}

bool BST::IsEmpty()const {
  return (size == 0);
}

void BST::Clear() {
    ClearR(root);
    root = NULL;
    size = 0;
}

int BST::GetSize()const {
  return size;
}

BSTNode * BST::Insert(const string & v) {
  size++;
  if(root == NULL) {
    root = new BSTNode(v);
    return this->root;
  } else {
    return InsertS(v,this->root);
  }
}

BSTNode * BST::InsertS(const string & v, BSTNode * p) {
  if(v == p->value) {
    size--;
    return NULL;
  } else if (p->value > v) {
    if(p->left) {
      return InsertS(v,p->left);
    } else {   
      p->left = new BSTNode(v);
      return p->left;
    }  
  } else if(p->value < v) {
    if(p->right) {
      return InsertS(v,p->right);
    } else {
      p->right = new BSTNode(v);
      return p->right;
    }
  }
  return NULL;
}

BSTNode * BST::Find(const string & v)const {
  return FindS(v,root);
}

BSTNode * BST::FindS(const string & v,BSTNode * p)const {
  if(p == NULL) {
    return NULL;
  } else if(p->GetValue() == v) {
    BSTNode * s = p;
    return s;
  } else if(p->GetValue() > v) {
    return FindS(v,p->left);
  } else if(p->GetValue() < v) {
    return FindS(v,p->right);
  }
  return NULL;
}


