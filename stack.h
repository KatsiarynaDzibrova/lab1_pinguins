#ifndef STACK_H
#define STACK_H
#include "math.h"

using namespace std;

class Stack {
public:
  explicit Stack(int max_size = 100);

  int Size() const;

  bool IsEmpty() const;

  bool IsFull() const;

  void Resize(int new_size_);

  bool PushBack(int value);

  bool PopBack();

  bool operator==(const Stack& other) const;

  ~ Stack();

private:
  int* data_;
  int max_size_;
  int tail_;
};

#endif // STACK_H
