#include "header.h"

// ==================== Node Class ====================

/**
 * @brief Constructor for Node
 * @param data Value to store in the node
 * Initializes next pointer to nullptr
 */
Node::Node(int data) : data(data), next(nullptr) {}

/**
 * @brief Destructor for Node
 * Prints debug message when node is deleted
 */
Node::~Node() {
  // cout << "node with data " << data << " is deleted" << endl;
}

/**
 * @brief Set the data of the node
 * @param data New data to set
 */
void Node::setData(int data) { this->data = data; }

/**
 * @brief Set the next node pointer
 * @param next Pointer to the next node
 */
void Node::setNext(Node *next) { this->next = next; }

/**
 * @brief Get the data stored in node
 * @return int Data value
 */
int Node::getData() { return this->data; }

/**
 * @brief Get the next node pointer
 * @return Node* Pointer to next node
 */
Node *Node::getNext() { return this->next; }

// ==================== LinkedList Class ====================

/**
 * @brief Constructor for LinkedList
 * Initializes head to nullptr
 */
LinkedList::LinkedList() : head(nullptr) {}

/**
 * @brief Destructor for LinkedList
 * Deletes all nodes and prints debug message
 */
LinkedList::~LinkedList() {
  // Node *iterator = head;
  // while (iterator != nullptr) {
  //   Node *temp = iterator;
  //   iterator = iterator->getNext();
  //   delete temp;
  // }
  // head = nullptr;
  // cout << "linkedlist is destroyed" << endl;
}

/**
 * @brief Insert a new node at the end of the list
 * @param data Value to insert
 * @return true if insertion succeeded, false otherwise
 */
bool LinkedList::insert(int data) {
  Node *newNode = new Node(data);
  if (newNode == nullptr)
    return false;

  if (head == nullptr) {
    head = newNode; // first node
    return true;
  }

  Node *iterator = head;
  while (iterator->getNext() != nullptr)
    iterator = iterator->getNext();

  iterator->setNext(newNode);
  return true;
}
// Suggestion: For performance, maintain a tail pointer to avoid traversing
// entire list on each insert.

/**
 * @brief Display list in normal order
 */
void LinkedList::display() {
  if (head == nullptr) {
    cout << "List is Empty" << endl;
    return;
  }

  Node *iterator = head;
  while (iterator != nullptr) {
    cout << iterator->getData();
    if (iterator->getNext() != nullptr)
      cout << " --> ";
    iterator = iterator->getNext();
  }
  cout << endl;
}

/**
 * @brief Insert a node at a specific 1-based position
 * If position > length, node is appended at the end
 * @param data Value to insert
 * @param pos 1-based position
 * @return true if insertion succeeded, false otherwise
 */
bool LinkedList::insertAt(int data, int pos) {
  if (pos <= 0)
    return false;

  Node *newNode = new Node(data);
  if (newNode == nullptr)
    return false;

  if (pos == 1 || head == nullptr) {
    newNode->setNext(head);
    head = newNode;
    return true;
  }

  Node *iterator = head;
  int counter = 1;
  while (iterator->getNext() != nullptr && counter < pos - 1) {
    iterator = iterator->getNext();
    counter++;
  }

  newNode->setNext(iterator->getNext());
  iterator->setNext(newNode);

  if (counter < pos - 1) {
    cout << "Position out of bounds, node inserted at last position "
         << counter + 1 << endl;
  }
  return true;
}
// Suggestion: Could return actual position where node was inserted for more
// feedback.

/**
 * @brief Replace all occurrences of prevData with newData
 * @param prevData Value to replace
 * @param newData New value
 * @return true if at least one node was replaced, false otherwise
 */
bool LinkedList::replaceAll(int prevData, int newData) {
  Node *iterator = head;
  bool replaced = false;
  int counter = 0;

  while (iterator != nullptr) {
    if (iterator->getData() == prevData) {
      iterator->setData(newData);
      replaced = true;
      counter++;
    }
    iterator = iterator->getNext();
  }

  if (replaced)
    cout << counter << " nodes are replaced " << endl;
  else
    cout << "no Match found " << endl;

  return replaced;
}

/**
 * @brief Find the length of the linked list
 * @return int Number of nodes in list (0 if empty)
 */
int LinkedList::length() const {
  int counter = 0;
  Node *iterator = head;
  while (iterator != nullptr) {
    iterator = iterator->getNext();
    counter++;
  }
  return counter;
}

/**
 * @brief Display linked list in reverse order (using recursion)
 */
void LinkedList::displayReverse() {
  if (head == nullptr) {
    cout << "List is Empty" << endl;
    return;
  }
  displayNode(head);
  cout << endl;
}

/**
 * @brief Helper function for recursive reverse display
 * @param current Current node
 */
void LinkedList::displayNode(Node *current) {
  if (current->getNext() != nullptr)
    displayNode(current->getNext());

  cout << current->getData();
  if (current != head)
    cout << " --> ";
}

/**
 * @brief Find the first node containing given data
 * @param data Value to find
 * @return Node* Pointer to node if found, nullptr otherwise
 */
Node *LinkedList::find(int data) {
  Node *iterator = head;
  while (iterator != nullptr) {
    if (iterator->getData() == data)
      return iterator;
    iterator = iterator->getNext();
  }
  return nullptr;
}
void LinkedList::reverseLinkedList() {
  if (head == nullptr || head->getNext() == nullptr)
    return;

  Node *p1 = nullptr;
  Node *p2 = head;
  Node *p3 = nullptr;

  while (p2 != nullptr) {
    p3 = p2->getNext(); // store next node
    p2->setNext(p1);    // reverse the link
    p1 = p2;            // move p1 forward
    p2 = p3;            // move p2 forward
  }

  head = p1; // new head is the last processed node
}

bool LinkedList::deleteNodeByPosition(int pos) {
  if (head == nullptr || pos < 1)
    return false;
  if (pos == 1) {
    Node *temp = head;
    head = head->getNext();
    delete temp;
    return true;
  }
  Node *prev = head;
  for (int i = 1; i < pos - 1; i++) {
    prev = prev->getNext();
    // if (prev == nullptr)//causes segmentation fault
    if (prev == nullptr || prev->getNext() == nullptr)
      return false; // position out of bound
  }
  Node *temp = prev->getNext();
  prev->setNext(temp->getNext());
  delete temp;
  return true;
}

bool LinkedList::deleteNodeByValue(int value) {
  if (head == nullptr)
    return false;
  if (head->getData() == value) {
    Node *temp = head;
    head = temp->getNext();
    delete temp;
    return true;
  }
  Node *prev = head, *temp = head->getNext();
  while (temp != nullptr && temp->getData() != value) {
    prev = temp;
    temp = temp->getNext();
  }
  if (temp == nullptr)
    return false; // value not found
  prev->setNext(temp->getNext());
  delete temp;
  return true;
}
