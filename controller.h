#pragma once
#include <string>
#include "Stack.h"
#include "abstractcontroller.h"
#include "MainWindowView.h"

class controller : public AbstractController
{
public:
	controller() = default;
	~controller() = default;
	void AddPinguin(std::string name) override;
	void PopBack() override;
	int Size() override;
	std::string Top() override;
	bool Compare(Stack& stack2) override;
private:
	Stack stack1;
};

