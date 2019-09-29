#include "controller.h"
#include <iostream>

controller::controller(MainWindowView* ptr): 
	view(ptr), iterator1(stack1.begin()) {
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

void controller::GoUp() {
	++iterator1;
	if (iterator1 == stack1.end()) { 
		--iterator1; 
	}
	view->ShowPicked(*iterator1);
}

void controller::GoDown() {
	if (iterator1 != stack1.begin()){
	--iterator1;
	}
	view->ShowPicked(*iterator1);
}


void controller::ChangeCurrentName(std::string s) {
	view->ClearView();
	iterator1[0] = s;
	for (Stack::Iterator it = stack1.begin(); it != stack1.end(); ++it) {
		view->ShowPinguin(*it);
	}
}