#include "Stack.h"


Stack::Iterator::Iterator(Stack* s, int i):stack_(s), index(i) {

}

Stack::Iterator Stack::begin(){
		return Iterator(this, 0);
}

const std::string& Stack::Iterator::operator*() const {
	return stack_->data_[index];
}

Stack::Iterator& Stack::Iterator::operator++() {
	index++;
	return *this;
}

Stack::Iterator& Stack::Iterator::operator--() {
	index--;
	return *this;
}
