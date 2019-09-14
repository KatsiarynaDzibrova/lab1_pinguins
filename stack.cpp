#include "stack.h"

Stack::Stack(int max_size) :
  max_size_(max_size), tail_(0) {
  string* copy_ = new string[max_size_];
  data_ = copy_;
}

int Stack::Size() const {
  return tail_;
}

string Stack::Top() {
    if (tail_ != 0) {
      return data_[tail_ - 1];
    }
  }

bool Stack::IsEmpty() const {
  return tail_ == 0;
}

bool Stack::IsFull() const {
  return tail_ == max_size_;
}

void Stack::Resize(int new_size_) {
  string* big_copy_ = new string[new_size_];
  for (int i = 0; i < fmin(tail_, new_size_); i++) {
    big_copy_[i] = data_[i];
  }
  delete[] data_;
  data_ = big_copy_;
  max_size_ = new_size_;
}

bool Stack::PushBack(int value) {
  if (IsFull()) {
    Resize(2 * max_size_);
  }
  data_[tail_] = value;
  tail_++;
  return true;
}

bool Stack::PopBack() {
  if (IsEmpty()) {
    return false;
  }
  tail_--;
  if (tail_ < (max_size_ * 0.5)) {
    Resize(max_size_ * 0.5);
  }
  return true;
}

bool Stack::operator==(const Stack& other) const {
  if (tail_ != other.Size()) {
    return false;
  }
  for (int i = 0; i < other.Size(); i++) {
    if (data_[i] != other.data_[i]) {
      return false;
    };
  }
  return true;
}

Stack::~Stack() {
  delete[] data_;
}

