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

	void GoUp() override;
	void GoDown() override;
	void ChangeCurrentName(std::string s);
private:
	MainWindowView* view;
	Stack stack1;
	Iterator iterator1;
	Stack stack2;
};

