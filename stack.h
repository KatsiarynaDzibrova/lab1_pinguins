#ifndef STACK_H
#define STACK_H
#include "math.h"
#include <string>

using namespace std;

class Stack {
public:
  explicit Stack(int max_size = 100);

  int Size() const;
  
  string Top();

  bool IsEmpty() const;

  bool IsFull() const;

  void Resize(int new_size_);

  bool PushBack(string value);

  bool PopBack();

  bool operator==(const Stack& other) const;

  ~ Stack();

private:
  string* data_;
  int max_size_;
  int tail_;
};

#endif // STACK_H
