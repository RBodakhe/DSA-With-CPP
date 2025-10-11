#include "header.h"

int main() {
  CircularLinkedList cll;
  cll.deleteByPosition(1);
  cll.insertAt(70, 1);
  cll.display();
  cll.deleteByPosition(1);
  cll.insertAt(80, 1);
  cll.insertEnd(10);
  cll.display();
  cll.insertEnd(20);
  cll.insertEnd(30);
  cll.insertEnd(40);

  cll.display();
  cll.insertAt(60, 3);
  cll.insertAt(50, 8);
  cll.insertAt(90, 10);
  cll.display();

  cll.deleteByPosition(5);
  cll.deleteByPosition(6);
  cll.display();
  cll.deleteByPosition(6);
  cll.display();
  return 0;
}