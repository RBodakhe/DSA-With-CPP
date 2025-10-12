#include "header.h"

int main() {

  Queue q1(5);
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 10 " << q1.enqueue(10) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 20 " << q1.enqueue(20) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 30 " << q1.enqueue(30) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 40 " << q1.enqueue(40) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 50 " << q1.enqueue(50) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "dequeue 10 " << q1.dequeue() << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  cout << "enqueue 60 " << q1.enqueue(60) << endl;
  cout << "is empty " << q1.isEmpty() << endl;
  cout << "is full " << q1.isFull() << endl;
  return 0;
}