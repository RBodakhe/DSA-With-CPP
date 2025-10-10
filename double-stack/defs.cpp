#include "header.h"
DoubleStack::DoubleStack(int size) {
  this->arr = new int[size];
  this->size = size;
  this->top1 = -1;
  this->top2 = size;
}
DoubleStack::~DoubleStack() { delete[] this->arr; }

bool DoubleStack::isEmpty1() const { return this->top1 == -1; }
bool DoubleStack::isEmpty2() const { return this->top2 == this->size; }
bool DoubleStack::isFull() const { return this->top1 == this->top2 - 1; }

bool DoubleStack::push1(int ele) {
  if (isFull())
    return false;
  this->arr[++this->top1] = ele;
  return true;
}
bool DoubleStack::push2(int ele) {
  if (isFull())
    return false;
  this->arr[--this->top2] = ele;
  return true;
}

int DoubleStack::pop1() {
  if (isEmpty1())
    return -999;
  return this->arr[this->top1--];
}
int DoubleStack::pop2() {
  if (isEmpty2())
    return -999;
  return this->arr[this->top2++];
}
int DoubleStack::peek1() const {
  if (isEmpty1())
    return -999;
  return this->arr[this->top1];
}
int DoubleStack::peek2() const {
  if (isEmpty2())
    return -999;
  return this->arr[this->top2];
}