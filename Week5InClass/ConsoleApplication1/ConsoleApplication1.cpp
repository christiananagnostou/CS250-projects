// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class myClass
{
public:
	double getWeight(){ return weight; }
	void setWeight(double W){ weight = W; }
	myClass(){ weight = 0; } //default constructor
	myClass(double W){ weight = W; } //params

	int fun(int x)
	{
		if (x > 4)  //base case
		{
			fun(x++);
		}
		else
		{
			return x+x;
		}
	}
private:
	double weight;
};

int calcSquare(int input)
{
	int square = 0;
	square = input*input;
	return square;
}
int checkFunction(int x = 16)
{
	return x;
}
int checkTwoNumbers( int x = 100, double d = 2.4)
{
	int sum = x + d;
	return sum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << checkTwoNumbers() << endl;

	cout << checkFunction(12) << endl;
	cout << checkFunction() << endl;

	cout << calcSquare(12) << endl;

	//step 2 declare
	myClass o1;
	cout << o1.getWeight() << endl;

	myClass o2(42);
	cout << o2.getWeight() << endl;

	//o1.fun(1);
	cout << o1.fun(1) << endl;

	system ("pause");
	return 0;
}


