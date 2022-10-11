// Author: Preet Dhadda
// Date: February 2022
#pragma once

#include "DequeT.h"

// QueueT class
template <class T>
class QueueT {
public: 
  // Constructor 
  QueueT();

  // enqueue method 
  void enqueue(T input);

  // dequeue method
  T dequeue();

  // empty method 
  bool empty() const;

  // size method
  int size() const;

private:
  // Attribute:
  DequeT<T> deque;
};

// ---------- IMPLEMENTATION DETAILS: ----------

// Constructor 
template <class T>
QueueT<T>::QueueT() {}

// enqueue method 
template <class T>
void QueueT<T>::enqueue(T input) {
  deque.insertBack(input);
}

// dequeue method
template <class T>
T QueueT<T>::dequeue() {
  return deque.removeFront();
}

// empty method 
template <class T>
bool QueueT<T>::empty() const {
  return deque.empty();
}

// size method
template <class T>
int QueueT<T>::size() const {
  return deque.size();
}