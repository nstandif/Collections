//
//  Project     : Collections I
//  File        : LinkedList.cpp
//  Description : Implementation of prototypes of LinkedList class in LinkedList.h
//  Author      : Nathan Standiford <ns@byu.edu>
//

#include "LinkedList.h"
#include <string>
using namespace std;

LinkedList::LinkedList() : first(NULL),last(NULL),size(0) {
}

LinkedList::LinkedList(const LinkedList & other) : first(NULL), last(NULL), size(0) {
  copy(other);
}

LinkedList &
LinkedList::operator= (const LinkedList & other) {
  if(this != &other) {
    copy(other);
  }
  return *this;
}

void
LinkedList::copy(const LinkedList & other) {
  Clear();
  LLNode * current = other.first;
  while(current) {
    Insert(current->value,last);
    current = current->next;
  }
}

LinkedList::~LinkedList() {
  Clear();
}

bool
LinkedList::IsEmpty()const {
  return !size;
}

void
LinkedList::Clear() {
  while(size)
    Remove(first);
}

int
LinkedList::GetSize()const {
  return size;
}

LLNode * 
LinkedList::GetFirst()const {
  return first;
}

LLNode *
LinkedList::GetLast()const {
  return last;
}

LLNode * 
LinkedList::Insert(const string & v, LLNode * n) {
  LLNode * node = new LLNode(v,NULL,NULL);
  size++;
  if(!first) {
    first = node;
    last = first;
    node = NULL;
    return first;
  }

  LLNode * current = NULL; 

  if(n) {
    current = advance(first,n);
  }

  if(!current) {
    node->next = first;
    first->prev = node;
    first = node;
    node = NULL;
    return first;
  }
 
  node->prev = current;
  node->next = node->prev->next;
  if(node->next) {
    node->next->prev = node;
  } else { 
    last = node;
  }
  node->prev->next = node;
  return node;
}

LLNode *
LinkedList::Find(const string & v, LLNode * n)const {
  if(n == NULL) {
    return LinkedList::FindS(v,first);
  } else {
    LLNode * current = advance(first,n);
    return LinkedList::FindS(v,current->next);
  }
}

LLNode *
LinkedList::FindS(const string & v, LLNode * current)const {
  if(current && current->value != v)
    return FindS(v,current->next);
  else
    return current;
}

LLNode *
LinkedList::advance(LLNode * current, LLNode * n)const {
  if(!Equals(current,n)) {
    return advance(current->next,n);
  } else {
    return current;
  }
}

bool
LinkedList::Equals(LLNode * n1, LLNode * n2)const {
  if(n1 == NULL || n2 == NULL)
    return false;

  return n1->next == n2->next
    && n1->prev == n2->prev
    && n1->value == n2->value;
}

void
LinkedList::Remove(LLNode * n) {
  if(first == last && n == first) {
    size = 0;
    first = NULL;
    last = NULL;
  } else if(n == first) {
    n->next->prev = NULL;
    first = n->next;
    size--;
  } else if(n == last) {
    n->prev->next = NULL;
    last = n->prev;
    size--;
  } else {
    n = advance(first,n);
    if(n != NULL) {
      n->next->prev = n->prev;  
      n->prev->next = n->next;
      size--;
    }
  }
  delete n;
  n = NULL;
}
