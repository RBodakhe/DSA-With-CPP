#include "header.h"
#include <iostream>
using namespace std;

int main() {
  LinkedList list1;

  cout << "Initial list length: " << list1.length() << endl;
  list1.display();

  // Insert nodes at end
  list1.insert(10);
  list1.insert(20);
  list1.insert(30);
  list1.insert(40);
  list1.insert(50);
  list1.insert(60);

  cout << "\nAfter inserting nodes at end:" << endl;
  list1.display();
  cout << "Length: " << list1.length() << endl;

  // Insert at specific positions
  list1.insertAt(70, 2);  // Insert at middle
  list1.insertAt(80, 12); // Insert out of bounds (appends at end)

  cout << "\nAfter insertAt operations:" << endl;
  list1.display();
  cout << "Length: " << list1.length() << endl;

  // Replace all occurrences
  list1.replaceAll(70, 90); // Should replace 2 nodes
  list1.display();

  list1.replaceAll(170, 30); // No match
  list1.display();

  // Display list in reverse
  cout << "\nDisplay list in reverse:" << endl;
  list1.displayReverse();

  list1.reverseLinkedList();
  list1.display();

  // delete by position
  cout << "delete by position\n";
  // list1.deleteNodeByPosition(0);
  // list1.display();
  // list1.deleteNodeByPosition(1);
  // list1.display();
  // list1.deleteNodeByPosition(4);
  // list1.display();
  // list1.deleteNodeByPosition(6);
  // list1.display();
  // list1.deleteNodeByPosition(7);
  // list1.display();
  // list1.deleteNodeByPosition(8);
  // list1.display();

  // delete by value

  list1.deleteNodeByValue(100);
  list1.display();
  list1.deleteNodeByValue(80);
  list1.display();
  list1.deleteNodeByValue(40);
  list1.display();
  list1.deleteNodeByValue(10);
  list1.display();
  // Find nodes
  // Node *found = list1.find(10);
  // if (found)
  //   cout << "\nFound node with value: " << found->getData() << endl;
  // else
  //   cout << "\nNode with value 10 not found" << endl;

  // Node *notFound = list1.find(100);
  // if (notFound)
  //   cout << "Found node with value: " << notFound->getData() << endl;
  // else
  //   cout << "Node with value 100 not found" << endl;

  // Destructor messages will appear when main() ends
  return 0;
}
