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
	void GenerateCrowd() override;
	void CrowdVisit() override;
	void StackVisit() override;
	Crowd crowd;
	Cahser cahser;
	void GoUp() override;
	void GoDown() override;
	
private:
	MainWindowView* view;
	Stack::Iterator iterator1;
	Stack stack2;
	Stack stack1;
};

