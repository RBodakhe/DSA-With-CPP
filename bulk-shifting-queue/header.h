#pragma once
#include <iostream>
using namespace std;
class Queue {
private:
  int *arr;
  int size;
  int front;
  int rear;

public:
  Queue(int = 5);
  ~Queue();
  bool isEmpty() const;
  bool isFull() const;
  bool enqueue(int);
  int dequeue();
  int peek() const;
};