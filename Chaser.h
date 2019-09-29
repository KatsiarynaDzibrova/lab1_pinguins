#pragma once

#include "Stack"

class Chaser : public Visitor {
public:
	void VisitStack(Stack& stack) {
		stack.PopBack();
	}
	void VisitCrowd(Crowd& crowd) {
		crowd.DeleteRandomHuman();
	}
};