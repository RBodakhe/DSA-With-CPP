#include "header.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
  this->size = size;
  arr = new int[size];
  front = -1;
  rear = -1;
}

Queue::~Queue() {
  cout << "Deleting queue\n";
  delete[] arr;
}

bool Queue::isEmpty() const {
  return front == -1;
}

bool Queue::isFull() const {
  return rear == size - 1;
}

bool Queue::enqueue(int data) {
  if (isFull()) {
    if (front > 0) {  // shift elements to reclaim space
      int j = 0;
      for (int i = front; i <= rear; i++)
        arr[j++] = arr[i];
      rear = j - 1;
      front = 0;
    } else {
      return false;  // truly full
    }
  }

  arr[++rear] = data;
  if (front == -1)
    front = 0;
  return true;
}

int Queue::dequeue() {
  if (isEmpty())
    return -999;

  int data = arr[front++];
  if (front > rear)
    front = rear = -1;
  return data;
}

int Queue::peek() const {
  if (isEmpty())
    return -999;
  return arr[front];
}
