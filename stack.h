#pragma once

#include "math.h"
#include <iostream>
#include <string>
#include "Iterator.h"
#include "Iterable.h"

using namespace std;


class Stack : Iterable {
public:

	explicit Stack(int max_size = 100) :
		max_size_(max_size), tail_(0) {
		string* copy_ = new string[max_size_];
		data_ = copy_;
	}

	int Size() const {
		return tail_;
	}

	bool IsEmpty() const {
		return tail_ == 0;
	}

	bool IsFull() const {
		return tail_ == max_size_;
	}

	void Resize(int new_size_) {
		string* big_copy_ = new string[new_size_];
		for (int i = 0; i < fmin(tail_, new_size_); i++) {
			big_copy_[i] = data_[i];
		}
		delete[] data_;
		data_ = big_copy_;
		max_size_ = new_size_;
	}

	bool PushBack(string value) {
		if (IsFull()) {
			Resize(2 * max_size_);
		}
		data_[tail_] = value;
		tail_++;
		return true;
	}

	bool PopBack() {
		if (IsEmpty()) {
			return false;
		}
		tail_--;
		if (tail_ < (max_size_ * 0.5)) {
			Resize(max_size_ * 0.5);
		}
		return true;
	}

	string Top() {
		if (tail_ != 0) {
			return data_[tail_ - 1];
		}
		return "";
	}

	bool operator==(const Stack& other) const {
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

	~Stack() {
		delete[] data_;
	}
	Iterator CreateIterator() override {
		return Iterator(data_, 0);
	}

	Iterator end() override {
		return Iterator(data_, Size());
	}
private:
	string* data_;
	int max_size_;
	int tail_;
};
 






