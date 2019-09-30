#pragma once
#include<string>
#include "abstractiterator.h"

class Iterator :AbstractlIterator {
public:
	Iterator(std::string* s, int i) : stack_(s), index(i) {}

	const std::string& operator*() const {
		return stack_[index];
	}

	Iterator& operator++() override {
		index = index + 1;
		return *this;
	}

	Iterator& operator--() override {
		index = index - 1;
		return *this;
	}


	bool operator!=(const Iterator& right) {
		return (index != right.index);
	}


	bool operator==(const Iterator& right) {
		return (index == right.index);
	}


	std::string& operator[](int i) {
		return stack_[index + i];
	}
private:
	std::string* stack_;
	int index;
};
