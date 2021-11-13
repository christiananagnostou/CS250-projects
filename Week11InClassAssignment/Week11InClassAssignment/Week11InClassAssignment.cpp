// Week11InClassAssignment.cpp : main project file.

#include "stdafx.h"
#include <iostream>
using namespace std;

class myCounter {
private:
	int theCounter;
public:
	myCounter(); //default constructor
	myCounter(int); //parameterized constructor
	int getValue();
	void operator ++ (); //overload prefix operator
	void operator ++ (int); //overloaded postfix operator
};

myCounter::myCounter() { theCounter = 0; } //constructor
myCounter::myCounter(int startValue) { theCounter = startValue; } //par construct
int myCounter::getValue(){ return theCounter; }

void myCounter::operator ++ () { ++theCounter; } //prefixvoid myCounter::operator ++ (int var) {++theCounter;} //postfix
void myCounter::operator ++ (int var) { ++theCounter; }

int main()
{
	myCounter counterObj;

	++counterObj;
	++counterObj;
	counterObj++;

	cout << counterObj.getValue() << "\n";

	cout << "___________________" << endl;
	int i = 0;
	int a = 0;
	cout << i << endl;
	cout << i++ << endl;
	cout << i << endl;
	cout << "___________________" << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	system("pause");
    return 0; 
}
