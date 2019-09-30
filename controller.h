#pragma once
#include <string>
#include "Stack.h"
#include "Chaser.h"
#include "abstractcontroller.h"
#include "MainWindowView.h"
#include "Iterator.h"

class controller : public AbstractController
{
public:
	controller(MainWindowView* ptr);
	~controller() = default;
	void AddPinguin(string name) override;
	void PopBack() override;
	int Size() override;
	string Top() override;
	void IfEqual() override;
	void GenerateCrowd() override;
	void CrowdVisit() override;
	void StackVisit() override;
	void GoUp() override;
	void GoDown() override;
	
private:
	MainWindowView* view;
	Iterator iterator1;
	Stack stack2;
	Stack stack1;
};

