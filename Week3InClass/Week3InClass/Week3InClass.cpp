// Week3InClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//crreate new data type
//step 1
class myFirstClass{
private:
	int x;
public:
	int getx() { return x; }
	void setx(int inX) { x = inX; }	//possible vaildation
	int y;	//NOT GOOD TO DO
};

int _tmain(int argc, _TCHAR* argv[])
{
//three steps
	//step 1 already defined
	//step 2 declare
	int x;
	//step 3 use
	x = 42;
	
	myFirstClass Object1;	//step 2
	//dot natation - whole.part and can only access public class members
	Object1.y = 12;	//step 3 use
	//Object1.x = 14;	x is private
	Object1.setx(42);
	cout << Object1.getx() << endl;

	system("pause");
	return 0;
}

