#pragma once
#include <iostream>

class DoubleStack {
private:
  int top1;
  int top2;
  int size;
  int *arr;

public:
  DoubleStack(int);
  ~DoubleStack();
  bool isEmpty1() const;
  bool isEmpty2() const;
  bool isFull() const;
  bool push1(int);
  bool push2(int);
  int pop1();
  int pop2();
  int peek1() const;
  int peek2() const;
};
