#include "queue.h"

Queue::Queue(size_t max_size) : data_(max_size) {}
bool Push(int value) {
  return data_.PushBack(value);
}


