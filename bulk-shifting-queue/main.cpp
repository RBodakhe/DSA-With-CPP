#include "header.h"

int main() {
  // Create a queue of size 5
  Queue q(5);

  cout << "\n--- Enqueuing elements ---\n";
  for (int i = 1; i <= 3; i++) {
    if (q.enqueue(i * 10))
      cout << "Enqueued: " << i * 10 << endl;
    else
      cout << "Queue is full, cannot enqueue " << i * 10 << endl;
  }

  cout << "\n--- Dequeuing 2 elements ---\n";
  cout << "Dequeued: " << q.dequeue() << endl;
  cout << "Dequeued: " << q.dequeue() << endl;

  cout << "\n--- Enqueuing more elements (should trigger bulk shift) ---\n";
  for (int i = 4; i <= 7; i++) {
    if (q.enqueue(i * 10))
      cout << "Enqueued: " << i * 10 << endl;
    else
      cout << "Queue is full, cannot enqueue " << i * 10 << endl;
  }

  cout << "\n--- Peek front element ---\n";
  cout << "Front: " << q.peek() << endl;

  cout << "\n--- Dequeuing all elements ---\n";
  while (!q.isEmpty()) {
    cout << "Dequeued: " << q.dequeue() << endl;
  }

  cout << "\n--- Trying to dequeue from empty queue ---\n";
  cout << "Dequeued: " << q.dequeue() << endl;

  cout << "\nProgram finished.\n";
  return 0;
}
