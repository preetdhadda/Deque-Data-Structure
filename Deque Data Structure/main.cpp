#include "DequeT.h"
#include "QueueT.h"
#include <iostream>
#include <string.h>

using std::string;
using std::cout;
using std::endl;

// ----------------- DEQUE INT TESTS -----------------
// ---------- test copy constructor dequeT (int) ----------
void testCopyConstructorInt() {
  cout << "TESTING COPY CONSTRUCTOR ON DEQUET:" << endl << endl;

  DequeT<int> deque1;
  deque1.insertFront(1);
  deque1.insertFront(2);
  deque1.insertFront(3);
  deque1.insertFront(4);
  deque1.insertFront(5);

  DequeT<int> deque2(deque1);
  cout << "deque1: " << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl; 
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  cout << "deque2:" << endl;
  deque2.print();
  cout << "deque2 size = " << deque2.size() << endl;
  cout << "deque2 front = " << deque2.peekFront() << endl; 
  cout << "deque2 back = " << deque2.peekBack() << endl << endl;

  DequeT<int> deque3(deque2);
  cout << "deque3:" << endl;
  deque3.print();
  cout << "deque3 size = " << deque3.size() << endl;
  cout << "deque3 front = " << deque3.peekFront() << endl; 
  cout << "deque3 back = " << deque3.peekBack() << endl << endl;

  deque1.~DequeT();
  deque2.~DequeT();
  deque3.~DequeT();
}

// ---------- test assign operator dequeT (int) ----------
void testOperatorInt() {
  cout << "TESTING OVERLOADED ASSIGNMENT OPERATOR ON DEQUET:" << endl << endl;

  DequeT<int> deque1;
  deque1.insertFront(1);
  deque1.insertFront(2);
  deque1.insertFront(3);
  deque1.insertFront(4);
  deque1.insertFront(5);

  DequeT<int> deque2;
  deque2.insertFront(20);
  deque2.insertFront(25);
  deque2.insertFront(30);

  deque2 = deque1;
  cout << "deque1:" << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl;
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  cout << "deque2:" << endl;
  deque2.print();
  cout << "deque2 size = " << deque2.size() << endl;
  cout << "deque2 front = " << deque2.peekFront() << endl;
  cout << "deque2 back = " << deque2.peekBack() << endl << endl;

  deque1 = deque2;
  cout << "deque1:" << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl;
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  if (deque2.empty() == true) {cout << "deque2 is now empty" << endl;}
  else {cout << "deque2 is not empty" << endl;}
  cout << "deque2 size = " << deque2.size() << endl << endl;

  DequeT<int> deque3;
  deque3.insertFront(6);
  deque3.insertFront(7);
  deque3.insertFront(8);
  deque3.insertFront(9);
  deque3.insertFront(10);

  cout << "deque3 before self-assignment:" << endl;
  deque3.print();
  deque3 = deque3;
  cout << "deque3 after self-assignment:" << endl;
  deque3.print();
  cout << "deque3 size = " << deque3.size() << endl;
  cout << "deque3 front = " << deque3.peekFront() << endl;
  cout << "deque3 back = " << deque3.peekBack() << endl << endl;

  deque1.~DequeT();
  deque2.~DequeT();
  deque3.~DequeT();
}


// --- test inserts, peeks, size, and empty dequeT (int) ---
void testInsertsInt() {
  cout << "TESTING INSERTS, PEEKS, SIZE, AND EMPTY ON DequeT:" << endl << endl;

  cout << "-----------------------------" << endl;
  DequeT<int> deque1;
  deque1.insertBack(3);
  deque1.print();
  // 3
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertFront(1);
  deque1.print();
  // 1 -> 3
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertFront(2);
  deque1.print();
  // 2 -> 1 -> 3
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertBack(7);
  deque1.print();
  // 2 -> 1 -> 3 -> 7
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  deque1.removeFront();
  // 1 -> 3 -> 7
  deque1.removeBack();
  // 1 -> 3
  deque1.removeBack();
  // 1
  deque1.removeFront();
  // empty deque
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl << endl;

  cout << "-----------------------------" << endl;
  deque1.insertFront(13);
  deque1.insertFront(18);
  deque1.insertBack(21);
  deque1.print();
  // 18 -> 13 -> 21
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;

  deque1.~DequeT();
}

// --- test removes, peeks, size, & empty dequeT (int) ---
void testRemovesInt() {
  cout << "TESTING REMOVES, PEEKS, SIZE, & EMPTY ON DequeT:" << endl << endl;

  cout << "-----------------------------" << endl;
  DequeT<int> deque;
  deque.insertFront(1);
  deque.insertFront(2);
  deque.insertFront(3);
  deque.insertFront(4);
  deque.insertFront(5);
  // 5 -> 4 -> 3 -> 2 -> 1
  deque.print();
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl << endl;

  cout << "-----------------------------" << endl;
  int remove1 = deque.removeFront();
  // 4 -> 3 -> 2 -> 1
  deque.print();
  cout << "- removeFront() = " << remove1 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  int remove2 = deque.removeBack();
  // 4 -> 3 -> 2
  deque.print();
  cout << "- removeBack() = " << remove2 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  int remove3 = deque.removeBack();
  // 4 -> 3
  deque.print();
  cout << "- removeBack() = " << remove3 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  int remove4 = deque.removeFront();
  // 3
  deque.print();
  cout << "- removeFront() = " << remove4 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  int remove5 = deque.removeFront();
  // empty deque
  cout << "- removeFront() = " << remove5 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;

  // All of the following should throw runtime errors, uncomment to test:
  // deque.peekFront();
  // deque.peekBack();
  // deque.removeFront();
  // deque.removeBack();

  deque.~DequeT();
}

// ----------------- DEQUE STRING TESTS -----------------

// ---------- test copy constructor dequeT (string) ----------
void testCopyConstructorStr() {
  cout << "TESTING COPY CONSTRUCTOR ON DEQUET:" << endl << endl;

  DequeT<string> deque1;
  deque1.insertFront("dog");
  deque1.insertFront("cat");
  deque1.insertFront("bird");
  deque1.insertFront("pig");
  deque1.insertFront("horse");

  DequeT<string> deque2(deque1);
  cout << "deque1: " << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl; 
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  cout << "deque2:" << endl;
  deque2.print();
  cout << "deque2 size = " << deque2.size() << endl;
  cout << "deque2 front = " << deque2.peekFront() << endl; 
  cout << "deque2 back = " << deque2.peekBack() << endl << endl;

  DequeT<string> deque3(deque2);
  cout << "deque3:" << endl;
  deque3.print();
  cout << "deque3 size = " << deque3.size() << endl;
  cout << "deque3 front = " << deque3.peekFront() << endl; 
  cout << "deque3 back = " << deque3.peekBack() << endl << endl;

  deque1.~DequeT();
  deque2.~DequeT();
  deque3.~DequeT();
}

// ---------- test assign operator dequeT (string) ----------
void testOperatorStr() {
  cout << "TESTING OVERLOADED ASSIGNMENT OPERATOR ON DEQUET:" << endl << endl;

  DequeT<string> deque1;
  deque1.insertFront("dog");
  deque1.insertFront("cat");
  deque1.insertFront("bird");
  deque1.insertFront("pig");
  deque1.insertFront("horse");

  DequeT<string> deque2;
  deque2.insertFront("donkey");
  deque2.insertFront("giraffe");
  deque2.insertFront("flamingo");

  deque2 = deque1;
  cout << "deque1:" << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl;
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  cout << "deque2:" << endl;
  deque2.print();
  cout << "deque2 size = " << deque2.size() << endl;
  cout << "deque2 front = " << deque2.peekFront() << endl;
  cout << "deque2 back = " << deque2.peekBack() << endl << endl;

  deque1 = deque2;
  cout << "deque1:" << endl;
  deque1.print();
  cout << "deque1 size = " << deque1.size() << endl;
  cout << "deque1 front = " << deque1.peekFront() << endl;
  cout << "deque1 back = " << deque1.peekBack() << endl << endl;

  if (deque2.empty() == true) {cout << "deque2 is now empty" << endl;}
  else {cout << "deque2 is not empty" << endl;}
  cout << "deque2 size = " << deque2.size() << endl << endl;

  DequeT<string> deque3;
  deque3.insertFront("rat");
  deque3.insertFront("frog");
  deque3.insertFront("bunny");
  deque3.insertFront("chipmunk");
  deque3.insertFront("monkey");

  cout << "deque3 before self-assignment:" << endl;
  deque3.print();
  deque3 = deque3;
  cout << "deque3 after self-assignment:" << endl;
  deque3.print();
  cout << "deque3 size = " << deque3.size() << endl;
  cout << "deque3 front = " << deque3.peekFront() << endl;
  cout << "deque3 back = " << deque3.peekBack() << endl << endl;

  deque1.~DequeT();
  deque2.~DequeT();
  deque3.~DequeT();
}


// --- test inserts, peeks, size, and empty dequeT (string) ---
void testInsertsStr() {
  cout << "TESTING INSERTS, PEEKS, SIZE, AND EMPTY ON DequeT:" << endl << endl;

  cout << "-----------------------------" << endl;
  DequeT<string> deque1;
  deque1.insertBack("pig");
  deque1.print();
  // pig
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertFront("dog");
  deque1.print();
  // dog -> pig
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertFront("cat");
  deque1.print();
  // cat -> dog -> pig
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;


  cout << "-----------------------------" << endl;
  deque1.insertBack("horse");
  deque1.print();
  // cat -> dog -> pig -> horse
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  deque1.removeFront();
  // dog -> pig -> horse
  deque1.removeBack();
  // dog -> pig
  deque1.removeBack();
  // dog
  deque1.removeFront();
  // empty deque
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl << endl;

  cout << "-----------------------------" << endl;
  deque1.insertFront("monkey");
  deque1.insertFront("giraffe");
  deque1.insertBack("flamingo");
  deque1.print();
  // giraffe -> monkey -> flamingo
  if (deque1.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque1.size() << endl;
  cout << "- front = " << deque1.peekFront() << endl;
  cout << "- back = " << deque1.peekBack() << endl << endl;

  deque1.~DequeT();
}

// --- test removes, peeks, size, & empty dequeT (string) ---
void testRemovesStr() {
  cout << "TESTING REMOVES, PEEKS, SIZE, & EMPTY ON DequeT:" << endl << endl;

  cout << "-----------------------------" << endl;
  DequeT<string> deque;
  deque.insertFront("dog");
  deque.insertFront("cat");
  deque.insertFront("bird");
  deque.insertFront("pig");
  deque.insertFront("horse");
  // horse -> pig -> bird -> cat -> dog
  deque.print();
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl << endl;

  cout << "-----------------------------" << endl;
  string remove1 = deque.removeFront();
  // pig -> bird -> cat -> dog
  deque.print();
  cout << "- removeFront() = " << remove1 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  string remove2 = deque.removeBack();
  // pig -> bird -> cat
  deque.print();
  cout << "- removeBack() = " << remove2 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  string remove3 = deque.removeBack();
  // pig -> bird 
  deque.print();
  cout << "- removeBack() = " << remove3 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  string remove4 = deque.removeFront();
  // bird 
  deque.print();
  cout << "- removeFront() = " << remove4 << endl;
  if (deque.empty() == true) {cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;
  cout << "- front = " << deque.peekFront() << endl;
  cout << "- back = " << deque.peekBack() << endl << endl;

  cout << "-----------------------------" << endl;
  string remove5 = deque.removeFront();
  // empty deque
  cout << "- removeFront() = " << remove5 << endl;
  if (deque.empty() == true) { cout << "- deque is empty" << endl;}
  else {cout << "- deque is not empty" << endl;}
  cout << "- deque size = " << deque.size() << endl;

  // All of the following should throw runtime errors, uncomment to test:
  // deque.peekFront();
  // deque.peekBack();
  // deque.removeFront();
  // deque.removeBack();

  deque.~DequeT();
}

// ----------------- QUEUE INT TESTS -----------------

// --- test enqueue, size, and empty for queue (ints) ---
void testEnqueueInt() {
  cout << "TESTING ENQUEUE, SIZE, AND EMPTY ON queueT (INT):" << endl << endl;

  QueueT<int> queue;

  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
  
  queue.enqueue(7);
  queue.enqueue(9);
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
}

// --- test enqueue, size, and empty for queue (strings) ---
void testEnqueueStr() {
  cout << "TESTING ENQUEUE, SIZE, AND EMPTY ON queueT (STRING):" << endl << endl;

  QueueT<string> queue;

  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue("wolf");
  queue.enqueue("bison");
  queue.enqueue("eagle");
  queue.enqueue("caribou");
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
  
  queue.enqueue("bear");
  queue.enqueue("coyote");
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
}

// --- test dequeue, size, and empty for queue (ints) ---
void testDequeueInt() {
  cout << "TESTING DEQUEUE, SIZE, AND EMPTY ON queueT (INT):" << endl << endl;

  QueueT<int> queue;

  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  int remove1 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove1 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
  
  int remove2 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove2 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue(9);
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  int remove3 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove3 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  int remove4 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove4 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  // queue.dequeue(); // should throw run time error
}

// --- test dequeue, size, and empty for queue (strings) ---
void testDequeueStr() {
  cout << "TESTING DEQUEUE, SIZE, AND EMPTY ON queueT (STRING):" << endl << endl;

  QueueT<string> queue;

  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue("cheetah");
  queue.enqueue("zebra");
  queue.enqueue("elephant");
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  string remove1 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove1 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;
  
  string remove2 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove2 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  queue.enqueue("tiger");
  queue.print();
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  string remove3 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove3 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  string remove4 = queue.dequeue();
  queue.print();
  cout << "- dequeue() = " << remove4 << endl;
  if (queue.empty() == true) {cout << "- queue is empty" << endl;}
  else {cout << "- queue is not empty" << endl;}
  cout << "- queue size = " << queue.size() << endl << endl;

  // queue.dequeue(); // should throw run time error
}


int main() {
  // ------- DequeT tests with type int -------
  testCopyConstructorInt();
  testOperatorInt();
  testInsertsInt();
  testRemovesInt();

  //------- DequeT tests with type string -------
  testCopyConstructorStr();
  testOperatorStr();
  testInsertsStr();
  testRemovesStr();

  //------- QueueT tests with type int -------
  testEnqueueInt();
  testDequeueInt();

  //------- QueueT tests with type string -------
  testEnqueueStr();
  testDequeueStr();
}