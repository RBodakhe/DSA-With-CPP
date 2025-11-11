#include "header.h"

Queue::Queue(int size) {
  this->totalSize = size;
  arr = new int[totalSize];
  front = -1;
  rear = -1;
  usedSize = 0;
}

Queue::~Queue() {
  delete[] arr;
}

bool Queue::isEmpty() const {
  return usedSize == 0;
}

bool Queue::isFull() const {
  return usedSize == totalSize;
}

int Queue::peek() const {
  if (isEmpty())
    return -999; // Imaginary number / error code
  return arr[(front + 1) % totalSize];
}

bool Queue::enqueue(int data) {
  if (isFull()) {
    return false;
  }
  rear = (rear + 1) % totalSize;
  arr[rear] = data;
  usedSize++;
  return true;
}

int Queue::dequeue() {
  if (isEmpty())
    return -999; // Imaginary number / error code
  front = (front + 1) % totalSize;
  int data = arr[front];
  usedSize--;
  return data;
}
