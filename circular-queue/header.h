#pragma once
#include <iostream>
using namespace std;

class Queue {
private:
  int *arr;
  int front;
  int rear;
  int totalSize;
  int usedSize;

public:
  Queue(int);
  ~Queue();

  bool isEmpty() const;
  bool isFull() const;
  int peek() const;
  bool enqueue(int);
  int dequeue();
};