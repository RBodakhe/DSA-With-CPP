#include "header.h"

int main() {
    // Create a queue of size 5
    Queue q(5);

    cout << "=== Queue Demo ===" << endl;

    // Enqueue elements
    cout << "Enqueuing 10, 20, 30..." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element (peek): " << q.peek() << endl;

    // Dequeue one element
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element after dequeue (peek): " << q.peek() << endl;

    // Enqueue more to test circular behavior
    cout << "Enqueuing 40, 50, 60..." << endl;
    q.enqueue(40);
    q.enqueue(50);

    // Try to enqueue when full
    if (!q.enqueue(60)) {
        cout << "Queue is full. Cannot enqueue 60." << endl;
    }

    // Dequeue all elements
    cout << "Dequeuing all elements: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    // Try dequeue on empty queue
    int val = q.dequeue();
    if (val == -999)
        cout << "Queue is empty. Cannot dequeue." << endl;

    cout << "=== End of Demo ===" << endl;
    return 0;
}
