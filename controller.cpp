#include "controller.h"
#include <iostream>



void controller::AddPinguin(std::string s) {
	stack1.PushBack(s);
	
	return;
}

void controller::PopBack() {
	stack1.PopBack();
	
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