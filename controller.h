#pragma once
#include <string>
#include "Stack.h"
class controller
{
public:
	controller();
	~controller() = default;
	void AddPinguin(std::string name);
	void PopBack();
	int Size();
	std::string Top();
private:
	Stack stack1;
};

