#pragma once
#include <iostream>

class Node {
private:
  int data;
  Node *next;

public:
  Node(int);
  ~Node();
  int getData() const;
  Node *getNext() const;
  void setData(int);
  void setNext(Node *);
};

class CircularLinkedList {
private:
  Node *head;

public:
  CircularLinkedList();
  ~CircularLinkedList();
  bool insertEnd(int);
  void display();
  bool insertAt(int, int);
  bool deleteByPosition(int);
  bool deleteByValue(int);
};