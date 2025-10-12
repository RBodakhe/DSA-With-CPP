#pragma once
#include <iostream>
using namespace std;
class Queue {
private:
  int *arr;
  int size;
  int front;
  int real;

public:
  Queue(int);
  ~Queue();
  bool isEmpty() const;
  bool isFull() const;
  bool enqueue(int);
  int dequeue();
};
