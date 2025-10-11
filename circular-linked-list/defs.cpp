#include "header.h"
using namespace std;
Node::Node(int data) : data(data), next(nullptr) {}
Node::~Node() {}

int Node::getData() const { return this->data; }
Node *Node::getNext() const { return this->next; }

void Node::setData(int data) { this->data = data; }
void Node::setNext(Node *next) { this->next = next; }

CircularLinkedList::CircularLinkedList() : head(nullptr) {}
CircularLinkedList::~CircularLinkedList() {
  if (head == nullptr)
    return;

  Node *temp = head->getNext();
  while (temp != head) {
    Node *del = temp;
    temp = temp->getNext();
    cout << "deleting " << del->getData() << endl;
    delete del;
  }

  cout << "deleting " << head->getData() << endl;
  delete head;
  head = nullptr;
}

bool CircularLinkedList::insertEnd(int data) {
  try {
    Node *newNode = new Node(data);

    if (head == nullptr) {
      head = newNode;
      newNode->setNext(head);
      return true;
    }
    Node *last = head;
    while (last->getNext() != head) {
      last = last->getNext();
    }
    last->setNext(newNode);
    newNode->setNext(head);
    return true;

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return false;
  }
}

void CircularLinkedList::display() {
  if (head == nullptr) {
    cout << "List is empty." << endl;
    return;
  }
  Node *temp = head;
  cout << "Circular Linked List: ";
  do {
    cout << temp->getData() << " -> ";
    temp = temp->getNext();
  } while (temp != head);
  cout << "(head)" << endl;
}

bool CircularLinkedList::insertAt(int data, int position) {
  if ((head == nullptr && position != 1) || position < 1)
    return false;
  try {
    Node *newNode = new Node(data);

    if (position == 1) {
      if (head == nullptr) {
        head = newNode;
        newNode->setNext(head);
        return true;
      }
      Node *last = head;
      while (last->getNext() != head) {
        last = last->getNext();
      }
      newNode->setNext(head);
      head = newNode;
      last->setNext(head);
      return true;
    }
    Node *prev = head;
    for (int i = 1; i < position - 1; i++) {
      prev = prev->getNext();
      if (prev == head) {
        delete newNode;
        cout << "Invalid position: " << position << endl;
        return false;
      }
    }
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
    return true;

  } catch (const std::bad_alloc &e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return false;
  }
}

bool CircularLinkedList::deleteByPosition(int position) {
  if (position < 1 || head == nullptr ||
      (head == head->getNext() && position != 1))
    return false;
  if (position == 1) {
    if (head == head->getNext()) {
      delete head;
      head = nullptr;
      return true;
    }
    Node *last = head;
    while (last->getNext() != head) {
      last = last->getNext();
    }
    Node *del = head;
    head = head->getNext();
    last->setNext(head);
    delete del;
    return true;
  }
  Node *prev = head;
  for (int i = 1; i < position - 1; i++) {
    prev = prev->getNext();
    if (prev->getNext() == head) {

      return false;
    }
  }
  Node *del = prev->getNext();
  prev->setNext(del->getNext());
  delete del;
  return true;
}

bool CircularLinkedList::deleteByValue(int value) {
  if (head == nullptr)
    return false;
  if (head->getData() == value) {
    if (head == head->getNext()) {
      delete head;
      head = nullptr;
      return true;
    }
    Node *last = head;
    while (last->getNext() != head) {
      last = last->getNext();
    }
    Node *del = head;
    head = head->getNext();
    last->setNext(head);
    delete del;
    return true;
  }
  Node *prev = head;
  Node *del = head;
  while (del->getData() != value) {
    prev = del;
    del = del->getNext();
    if (del == head)
      return false;
  }
  prev->setNext(del->getNext());
  delete del;
  return true;
}
