#pragma once
#include <iostream>
using std::cout;
using std::endl;

enum code{Success,Empty,overload};

typedef double StackSort;
const int tailleMax = 10;

class Pile {
public:
	Pile();
	~Pile();
	code push(const StackSort &);
	code pop();
	code top(StackSort &)const;
	code secondTop(StackSort &)const;
	code printStack()const;
	code trashStack();
	bool full()const;
	bool empty()const;
	int GetHowMuchElements()const;

private:
	StackSort StackArray[tailleMax];
	int HowMuchElements;

};