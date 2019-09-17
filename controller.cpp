#include "controller.h"
#include <iostream>


void controller::AddPinguin(std::string s) {
	stack1.PushBack(s);
	std::cout << std::endl << "pushed" << std::endl;
	return;
}

void controller::PopBack() {
	stack1.PopBack();
	std::cout << std::endl << "poped" << std::endl;
	return;
}
int controller::Size() {
	return stack1.Size();
}
std::string controller::Top() {
	return stack1.Top();
}
bool controller::Compare(Stack& stack2) {
	return stack1 == stack2;
}