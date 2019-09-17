#pragma once

#include <stack>
#include "abstractview.h"
#include <string>
#include "Stack.h"
class AbstractController
{
public:
	virtual ~AbstractController() = default;
	virtual void AddPinguin(std::string name) = 0;
	virtual void PopBack() = 0;
	virtual int Size() = 0;
	virtual std::string Top() = 0;
	virtual bool Compare(Stack& stack2) = 0;
};

