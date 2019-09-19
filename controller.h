#pragma once
#include <string>
#include "Stack.h"
#include "abstractcontroller.h"
#include "MainWindowView.h"

class controller : public AbstractController
{
public:
	controller(MainWindowView* ptr);
	~controller() = default;
	void AddPinguin(std::string name) override;
	void PopBack() override;
	int Size() override;
	std::string Top() override;
	void IfEqual() override;
private:
	MainWindowView* view;
	Stack stack1;
	Stack stack2;
};

