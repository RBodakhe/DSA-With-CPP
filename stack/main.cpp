#include "header.h"
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << "Enter stack size: ";
  cin >> size;

  Stack s(size);
  int choice, value;

  do {
    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek (Top Element)\n";
    cout << "4. Check if Empty\n";
    cout << "5. Check if Full\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to push: ";
      cin >> value;
      if (s.push(value))
        cout << "✅ " << value << " pushed successfully.\n";
      else
        cout << "❌ Stack is full! Cannot push.\n";
      break;

    case 2:
      value = s.pop();
      if (value != -999)
        cout << "✅ Popped element: " << value << endl;
      else
        cout << "❌ Stack is empty! Nothing to pop.\n";
      break;

    case 3:
      value = s.peek();
      if (value != -999)
        cout << "🔝 Top element: " << value << endl;
      else
        cout << "❌ Stack is empty!\n";
      break;

    case 4:
      cout << (s.isEmpty() ? "✅ Stack is empty.\n" : "❌ Stack is not empty.\n");
      break;

    case 5:
      cout << (s.isFull() ? "✅ Stack is full.\n" : "❌ Stack is not full.\n");
      break;

    case 6:
      cout << "👋 Exiting program.\n";
      break;

    default:
      cout << "⚠️ Invalid choice! Try again.\n";
      break;
    }

  } while (choice != 6);

  return 0;
}
