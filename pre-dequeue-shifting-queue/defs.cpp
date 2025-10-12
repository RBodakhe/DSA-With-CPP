#include "header.h"
Queue::Queue(int size) {
  this->size = size;
  this->arr = new int[size];
  this->front = -1;
  this->real = -1;
}
Queue::~Queue() {
  cout << "deleting queue" << endl;
  delete[] arr;
}
bool Queue::isEmpty() const { return front == -1; }
bool Queue::isFull() const { return real == size - 1; }
bool Queue::enqueue(int data) {
  if (isFull()) {
    return false;
  }
  if (front == -1) {
    front++;
  }
  arr[++real]=data;
  return true;
}
int Queue::dequeue() {
  if (isEmpty())
    return -999;
  int data = arr[front];
  if ((--real) == -1) {
    front = -1;
  }
  for (int i = 0; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
  return data;
}