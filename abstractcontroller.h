#pragma once

#include <stack>
#include "abstractview.h"
#include <string>
#include "Stack.h"
#include "Chaser.h"
class AbstractController
{
public:
	virtual ~AbstractController() = default;
	virtual void AddPinguin(std::string name) = 0;
	virtual void PopBack() = 0;
	virtual int Size() = 0;
	virtual std::string Top() = 0;
	virtual void IfEqual() = 0;
	virtual void GenerateCrowd() = 0;
	virtual void CrowdVisit() = 0;
	virtual void StackVisit() = 0;
	Crowd crowd;
	Chaser chaser;
	virtual void GoUp() = 0;
	virtual void GoDown() = 0;
	
};

