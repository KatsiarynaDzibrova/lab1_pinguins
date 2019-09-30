#pragma once
class AbstractlIterator {
public: 

	virtual AbstractlIterator& operator++() = 0;

	virtual AbstractlIterator& operator--() = 0;

};
