#pragma once

#include "math.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Visitor.h"

using namespace std;

class PeopleGroup {
public:
	virtual ~PeopleGroup() = default;
	virtual void Accept(Visitor& c) = 0;
};

class Stack : public PeopleGroup  {
public:
	class Iterator;

	explicit Stack(int max_size = 100) :
		max_size_(max_size), tail_(0) {
		string* copy_ = new string[max_size_];
		data_ = copy_;
	}

	int Size() const {
		return tail_;
	}

	bool IsEmpty() const {
		return tail_ == 0;
	}

	bool IsFull() const {
		return tail_ == max_size_;
	}

	void Resize(int new_size_) {
		string* big_copy_ = new string[new_size_];
		for (int i = 0; i < fmin(tail_, new_size_); i++) {
			big_copy_[i] = data_[i];
		}
		delete[] data_;
		data_ = big_copy_;
		max_size_ = new_size_;
	}

	bool PushBack(string value) {
		if (IsFull()) {
			Resize(2 * max_size_);
		}
		data_[tail_] = value;
		tail_++;
		return true;
	}

	bool PopBack() {
		if (IsEmpty()) {
			return false;
		}
		tail_--;
		if (tail_ < (max_size_ * 0.5)) {
			Resize(max_size_ * 0.5);
		}
		return true;
	}

	string Top() {
		if (tail_ != 0) {
			return data_[tail_ - 1];
		}
		return "";
	}

	bool operator==(const Stack& other) const {
		if (tail_ != other.Size()) {
			return false;
		}
		for (int i = 0; i < other.Size(); i++) {
			if (data_[i] != other.data_[i]) {
				return false;
			};
		}
		return true;
	}

	void Accept(Visitor& c) override {
		c.VisitStack(*this);
	}

	~Stack() {
		delete[] data_;
	}
	
	
	Stack::Iterator begin();

private:
	string* data_;
	int max_size_;
	int tail_;
};
 

class Stack::Iterator : 
	public std::iterator<std::random_access_iterator_tag, std::string> {
public:
	Iterator(Stack* s, int i);
	const std::string& operator*() const;
	Iterator& operator++();
	Iterator& operator--();
private:
	const Stack* stack_;
	int index;
};

class Crowd : public PeopleGroup
{
private:
	vector <string> crowd;
	int size_;

public:
	string items[20] = { "Lyosha", "Nikita", "Zhenya", "artemx",
		"Sasha", "rrenkens", "Katya", "Petya", "Sanya", "Dimka", "Lyosha", "Pasha",  "Andryusha", "Narodok", 
		 "Yanina", "Misha", "Alesya",
	"Stas", "Fedya", "Shnek"};
	
	explicit Crowd() : 
		crowd(vector<string>(rand() % 10 + 1)), 
		size_(crowd.size()) {
	}

	void DeleteRandomHuman() {
			crowd.erase(begin(crowd) + rand() % size_);
			size_--;
		}

	string GetHumanWithIndex(int index) {
		return crowd[index];
	}
	int GetSize() {
		return size_;
	}

	void GenerateRandomCrowd() {
		srand(time(NULL));
		vector <string> crowd1(rand() % 10 + 1);
		for (int i = 0; i < crowd1.size(); i++) {
			crowd1[i] = items[ rand() % (sizeof(items) / sizeof(items[0]))];
		}
		crowd = crowd1;
		size_ = crowd1.size();
	}

	void Accept(Visitor& c) override {
		c.VisitCrowd(*this);
	}
};





