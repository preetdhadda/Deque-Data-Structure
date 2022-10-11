// Author: Preet Dhadda
// Date: February 2022
#pragma once

#include <stdexcept>
using std::runtime_error;

// Node class for doubly LL
template <class T>
class Node {
public: 
  // Attributes:
  T data;
  Node* prev;
  Node* next;

  // Constructor with only the node data as a parameter
  Node(T val) : data(val), prev(nullptr), next(nullptr) { ; };

  // Constructor with node data, previous, and next values as parameters
  Node(T val, Node* prv, Node* nxt) : data(val), prev(prv), next(nxt) { ; };
};

// DequeT class
template <class T>
class DequeT {
public: 
  // Constructor
  DequeT();

  // Copy constructor 
  DequeT(const DequeT & deque);

  // Destructor
  ~DequeT();

  // Overloaded assignment operator
  DequeT& operator=(const DequeT & deque);

  // insertFront method
  void insertFront(T input);

  // insertBack method 
  void insertBack(T input);

  // removeFront method
  T removeFront();

  // removeBack method 
  T removeBack();

  // peekFront method
  T peekFront() const;

  // peekBack method
  T peekBack() const;

  // empty method
  bool empty() const;

  // size method 
  int size() const;

private:
  // Private attributes:
  Node<T>* front;
  Node<T>* back;

  // Deep copy helper method (used in copy constructor & operator)
  void copy(const DequeT & deque);

  // Delete deque helper method (used in destructor & operator) 
  void deleteDequeT();
};

// ---------- DEQUET IMPLEMENTATION DETAILS: ----------

// ------------ CONSTRUCTORS/DESTRUCTORS -------------

// Constructor
template <class T>
DequeT<T>::DequeT() {
  front = nullptr;
  back = nullptr;
}

// Copy constructor 
template <class T>
DequeT<T>::DequeT(const DequeT & deque) {
  copy(deque);
}

// Destructor
template <class T>
DequeT<T>::~DequeT() {
  deleteDequeT();
}

// Overloaded assignment operator --> don't think it is deleting the deque
template <class T>
DequeT<T>& DequeT<T>::operator=(const DequeT & deque) {
  // Only make copy if the address of calling object != address of parameter
  if (this != &deque) {
    deleteDequeT();
    copy(deque);
  }

  // Return pointer to calling object
  return *this;
}

// -------------------- METHODS --------------------

// insertFront method 
template <class T>
void DequeT<T>::insertFront(T input) {
  // Create node with input parameter
  Node<T>* newNode = new Node<T>(input);

  // If this is the 1st element in deque, set back & front = newNode
  if (front == nullptr) {
    front = newNode;
    back = newNode;
  }
  // Otherwise, update the node pointers:
  else {
    // Set newNode->next to be front & front->prev to be newNode
    newNode->next = front;
    front->prev = newNode;
    // Finally, set front = newNode
    front = newNode;
  }
}

// insertBack method 
template <class T>
void DequeT<T>::insertBack(T input) {
  // Create node with input parameter
  Node<T>* newNode = new Node<T>(input);

  // If this is the 1st element in deque, set back & front = newNode
  if (back == nullptr) {
    back = newNode;
    front = newNode;
  }
  // Otherwise, update the node pointers:
  else {
    // Set newNode->prev to be back & back->next to be newNode
    newNode->prev = back;
    back->next = newNode;
    // Finally, set back = newNode
    back = newNode;
  }
}

// removeFront method
template <class T>
T DequeT<T>::removeFront() {
  // Throw runtime error if deque is empty
  if (this->empty() == true) {
    throw runtime_error("Calling object is empty - cannot remove elements");
  }
  
  // Make temp node for front, move front to the right,
  // and delete temp 
  Node<T>* temp = front;
  T removed = temp->data;
  front = front->next;
  delete temp;

// Update node pointers:
  // If we just removed the last item, make back also = null
  if (front == nullptr) {
    back = nullptr;
  }
  // Otherwise, make front->prev null to remove data
  else {
    front->prev = nullptr;
  }

  return removed;
}

// removeBack method
template <class T>
T DequeT<T>::removeBack() {
  // Throw runtime error if deque is empty
  if (this->empty() == true) {
    throw runtime_error("Calling object is empty - cannot remove elements");
  }

  // Make temp node for back, move back to the left,
  // and delete temp
  Node<T>* temp = back; 
  T removed = temp->data;
  back = back->prev;
  delete temp;

// Update node pointers:
  // If we just removed the last item, make front also = null
  if (back == nullptr) {
    front = nullptr;
  }
  // Otherwise, make back->next null to remove data
  else {
    back->next = nullptr;
  }

  return removed;
}

// peekFront method
template <class T>
T DequeT<T>::peekFront() const {
  // Throw runtime error if deque is empty
  if (this->empty() == true) {
    throw runtime_error("Calling object is empty - cannot peek elements");
  }
  // Return data at front
  return front->data;
}

// peekBack method
template <class T>
T DequeT<T>::peekBack() const {
  // Throw runtime error if deque is empty
  if (this->empty() == true) {
    throw runtime_error("Calling is empty - cannot peek elements");
  }
  // Return data at back
  return back->data;
}

// empty method
template <class T>
bool DequeT<T>::empty() const {
  if (this->size() == 0) {
    return true;
  }
  else {
    return false;
  }
}

// size method 
template <class T>
int DequeT<T>::size() const {
  int n = 0;
  // Using a temp node, loop thru deque incrementing size
  Node<T>* temp = front;
  while (temp != nullptr) {
    n++;
    temp = temp->next;
  }
  return n;
}

// Deep copy helper method (used in copy constructor & operator)
template <class T>
void DequeT<T>::copy(const DequeT & deque) {
  // Initialize deque attributes
  front = nullptr;
  back = nullptr;
  // Create node pointing to the front of the original deque
  Node<T>* original = deque.front;

  // Copy the front of the deque
  if (deque.empty() == false) {
    front = new Node<T>(original->data);
    original = original->next;

    // Create node pointing to the front of the copied deque
    Node<T>* copy = front;

    // Copy the rest of the nodes into the new deque
    while (original != nullptr) {
      //Node<T>* newNode = new Node<T>(original->data);
    
      // If we've reached the last node in original, set it equal to back
      if (original->next == nullptr) {
        back = new Node<T>(original->data);
        copy->next = back;
      }
      
      // Otherwise, keep iterating and copying from original deque
      else {
        Node<T>* newNode = new Node<T>(original->data);
        copy->next = newNode;
      }

      //copy->next = newNode;
      original = original->next;
      copy = copy->next;
    }
    copy = nullptr;
    original = nullptr;
    delete copy;
    delete original;
  }
}

// Delete deque helper method (used in destructor & operator) 
template <class T>
void DequeT<T>::deleteDequeT() {
  // Create a temp node 
  Node<T>* temp = front;

  // Loop through deque deallocating memory from each node
  while (front != nullptr) {
    front = front->next;
    delete temp;
    temp = front;
  }

  front = nullptr; 
  back = nullptr;
}
