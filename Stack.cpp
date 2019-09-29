#include "Stack.h"


Stack::Iterator::Iterator(Stack* s, int i):stack_(s), index(i) {

}

Stack::Iterator Stack::begin() {
	return Iterator(this, 0);
}

Stack::Iterator Stack::end() {
	return Iterator(this, Size());
}



const std::string& Stack::Iterator::operator*() const {
	return stack_->data_[index];
}

Stack::Iterator& Stack::Iterator::operator++() {
	int size = stack_->Size();
	if (size != 0) {
		index = (index + size) % size + 1;
	}
	return *this;
}

Stack::Iterator& Stack::Iterator::operator--() {
	int size = stack_->Size();
	if (size != 0) {
		index = (index - 1 + size) % size;
	}
	return *this;
}


bool Stack::Iterator::operator!=(const Stack::Iterator& right) {
	return (index != right.index);
}


bool Stack::Iterator::operator==(const Stack::Iterator& right) {
	return (index == right.index);
}


std::string& Stack::Iterator::operator[](int i) {
	return stack_->data_[index];
}