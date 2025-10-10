#include "header.h"
#include <iostream>
using namespace std;

int main() {
  int size;
  cout << "Enter size of Double Stack: ";
  cin >> size;

  DoubleStack ds(size);
  int choice, value;

  do {
    cout << "\n======= Double Stack Menu =======\n";
    cout << "1. Push in Stack 1\n";
    cout << "2. Push in Stack 2\n";
    cout << "3. Pop from Stack 1\n";
    cout << "4. Pop from Stack 2\n";
    cout << "5. Peek Stack 1\n";
    cout << "6. Peek Stack 2\n";
    cout << "7. Check if Stack 1 Empty\n";
    cout << "8. Check if Stack 2 Empty\n";
    cout << "9. Check if Both Stacks Full\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to push in Stack 1: ";
      cin >> value;
      if (ds.push1(value))
        cout << "✅ " << value << " pushed to Stack 1.\n";
      else
        cout << "❌ Stack 1 is full.\n";
      break;

    case 2:
      cout << "Enter value to push in Stack 2: ";
      cin >> value;
      if (ds.push2(value))
        cout << "✅ " << value << " pushed to Stack 2.\n";
      else
        cout << "❌ Stack 2 is full.\n";
      break;

    case 3:
      value = ds.pop1();
      if (value != -999)
        cout << "✅ Popped from Stack 1: " << value << endl;
      else
        cout << "❌ Stack 1 is empty.\n";
      break;

    case 4:
      value = ds.pop2();
      if (value != -999)
        cout << "✅ Popped from Stack 2: " << value << endl;
      else
        cout << "❌ Stack 2 is empty.\n";
      break;

    case 5:
      value = ds.peek1();
      if (value != -999)
        cout << "🔝 Top of Stack 1: " << value << endl;
      else
        cout << "❌ Stack 1 is empty.\n";
      break;

    case 6:
      value = ds.peek2();
      if (value != -999)
        cout << "🔝 Top of Stack 2: " << value << endl;
      else
        cout << "❌ Stack 2 is empty.\n";
      break;

    case 7:
      cout << (ds.isEmpty1() ? "✅ Stack 1 is empty.\n"
                             : "❌ Stack 1 is not empty.\n");
      break;

    case 8:
      cout << (ds.isEmpty2() ? "✅ Stack 2 is empty.\n"
                             : "❌ Stack 2 is not empty.\n");
      break;

    case 9:
      cout << (ds.isFull() ? "⚠️ Both stacks are full.\n"
                           : "✅ There is still space in array.\n");
      break;

    case 10:
      cout << "👋 Exiting program...\n";
      break;

    default:
      cout << "⚠️ Invalid choice! Try again.\n";
      break;
    }
  } while (choice != 10);

  return 0;
}
