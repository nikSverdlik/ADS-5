// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <string>

template<typename T, int size>
class TStack {
 private:
  T arr[size] = {};
  int topIndex;

 public:
  TStack() {
    topIndex = -1;
  }

  bool isEmpty() {
    return topIndex == -1;
  }

  bool isFull() {
    return topIndex == size - 1;
  }

  void push(T value) {
    if (isFull()) {
      throw std::string("Stack is full!");
    }
    topIndex = topIndex + 1;
    arr[topIndex] = value;
  }

  T pop() {
    if (isEmpty()) {
      throw std::string("Stack is empty!");
    }
    T value = arr[topIndex];
    topIndex = topIndex - 1;
    return value;
  }

  T top() {
    if (isEmpty()) {
      throw std::string("Stack is empty!");
    }
    return arr[topIndex];
  }
};

#endif  // INCLUDE_TSTACK_H_
