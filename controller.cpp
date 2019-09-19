#include "controller.h"
#include <iostream>

controller::controller(MainWindowView* ptr): view(ptr){
	stack2.PushBack("Jake");
	stack2.PushBack("Finn");
}

void controller::AddPinguin(std::string s) {
	stack1.PushBack(s);
	view->ShowPinguin(s);
	return;
}

void controller::PopBack() {
	stack1.PopBack();
	view->HidePinguin();
	return;
}
int controller::Size() {
	return stack1.Size();
}
std::string controller::Top() {
	return stack1.Top();
}

void controller::IfEqual() {
	if (stack1 == stack2) {
		view->SetIfEqual("True");

	}
	else {
		view->SetIfEqual("False");
	}
}