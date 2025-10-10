#pragma once
#include <iostream>

/**
 * @class Stack
 * @brief Simple stack implementation using dynamic array
 */
class Stack {
private:
  int top;   ///< Index of the top element
  int size;  ///< Maximum size of stack
  int *arr;  ///< Pointer to dynamic array

public:
  /** 
   * @brief Constructor to create stack of given size
   * @param size Maximum number of elements stack can hold
   */
  Stack(int size);

  /** 
   * @brief Destructor to free allocated memory
   */
  ~Stack();

  /** 
   * @brief Push a new element on top of the stack
   * @param ele Element to be added
   * @return true if push successful, false if stack is full
   */
  bool push(int ele);

  /** 
   * @brief Remove element from top of the stack
   * @return The popped element, or -999 if stack is empty
   */
  int pop();

  /** 
   * @brief Get topmost element without removing it
   * @return The top element, or -999 if stack is empty
   */
  int peek() const;

  /** 
   * @brief Check if stack is empty
   * @return true if empty, false otherwise
   */
  bool isEmpty() const;

  /** 
   * @brief Check if stack is full
   * @return true if full, false otherwise
   */
  bool isFull() const;
};
