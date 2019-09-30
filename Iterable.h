#pragma once
#include"Iterator.h"
#include <string>

class Iterable {
public:
	virtual Iterator CreateIterator() = 0;
	virtual Iterator end() = 0;
};







