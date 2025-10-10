#include "header.h"

// Constructor
Stack::Stack(int size) {
  this->arr = new int[size];
  this->size = size;
  this->top = -1;
}

// Destructor
Stack::~Stack() { delete[] arr; }

// Check if stack is empty
bool Stack::isEmpty() const { return this->top == -1; }

// Check if stack is full
bool Stack::isFull() const { return this->top == this->size - 1; }

// Push element to stack
bool Stack::push(int ele) {
  if (isFull())
    return false;
  this->arr[++this->top] = ele;
  return true;
}

// Pop element from stack
int Stack::pop() {
  if (isEmpty())
    return -999;
  return this->arr[this->top--];
}

// Peek top element
int Stack::peek() const {
  if (isEmpty())
    return -999;
  return this->arr[this->top];
}