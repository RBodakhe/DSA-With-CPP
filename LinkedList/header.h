#pragma once
#include <iostream>
using namespace std;

/**
 * @class Node
 * @brief Represents a single node in a linked list.
 */
class Node {
private:
  int data;   ///< Data stored in the node
  Node *next; ///< Pointer to the next node

public:
  /**
   * @brief Constructor for Node
   * @param data Value to store in the node
   */
  Node(int data);

  /**
   * @brief Destructor for Node
   * Prints debug message when node is deleted
   */
  ~Node();

  /** @brief Set the data of the node */
  void setData(int data);

  /** @brief Get the data stored in the node */
  int getData();

  /** @brief Set the pointer to the next node */
  void setNext(Node *next);

  /** @brief Get the pointer to the next node */
  Node *getNext();
};

/**
 * @class LinkedList
 * @brief Singly linked list implementation.
 */
class LinkedList {
private:
  Node *head;               ///< Pointer to the first node
  void displayNode(Node *); ///< Helper for recursive reverse display

public:
  /** @brief Constructor initializes head to nullptr */
  LinkedList();

  /** @brief Destructor deletes all nodes and frees memory */
  ~LinkedList();

  /**
   * @brief Insert a new node at the end of the list
   * @param data Value to insert
   * @return true if insertion succeeded, false otherwise
   */
  bool insert(int data);

  /**
   * @brief Display the list in normal order
   */
  void display();

  /**
   * @brief Insert a node at a specific position (1-based index)
   * @param data Value to insert
   * @param pos Position to insert
   * @return true if insertion succeeded, false otherwise
   */
  bool insertAt(int data, int pos);

  /**
   * @brief Replace all occurrences of prev value with new value
   * @param prev Value to replace
   * @param newVal New value
   * @return true if at least one node was replaced, false otherwise
   */
  bool replaceAll(int prev, int newVal);

  /**
   * @brief Return the number of nodes in the list
   * @return int Length of the list
   */
  int length() const;

  /**
   * @brief Display the list in reverse order using recursion
   */
  void displayReverse();

  /**
   * @brief Find the first node containing the given data
   * @param data Value to find
   * @return Node* Pointer to the node if found, nullptr otherwise
   */
  Node *find(int data);

  void reverseLinkedList();

  bool deleteNodeByPosition(int);
  bool deleteNodeByValue(int);
};
