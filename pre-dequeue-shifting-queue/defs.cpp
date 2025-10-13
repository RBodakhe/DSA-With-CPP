#include "header.h"

Queue::Queue(int size) {
  this->size = size;
  this->arr = new int[size];
  this->front = -1;
  this->real = -1;
}

Queue::~Queue() {
  cout << "Deleting queue" << endl;
  delete[] arr;
}

bool Queue::isEmpty() const { return front == -1; }

bool Queue::isFull() const { return real == size - 1; }

bool Queue::enqueue(int data) {
  if (isFull()) {
    cout << "Queue overflow!" << endl;
    return false;
  }
  if (front == -1)
    front = 0;
  arr[++real] = data;
  return true;
}

int Queue::dequeue() {
  if (isEmpty()) {
    cout << "Queue underflow!" << endl;
    return -999;
  }

  int data = arr[front]; // store front element

  // Shift all elements one position left
  for (int i = 1; i <= real; i++) {
    arr[i - 1] = arr[i];
  }

  real--; // rear index moves left
  if (real < 0) {
    front = -1;
    real = -1;
  }

  return data;
}
