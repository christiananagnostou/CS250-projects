// ConsoleApplication1.cpp : main project file.

#include "stdafx.h"
#include <iostream>
using namespace std;
using namespace System;

class shape{
public:
	double dim1;
	void setDim1(int inDim1){ dim1 = inDim1; }
	virtual double getArea(){ return 0; }
};

class rectangle : public shape{
private:
	double dim2;
public:
	double getArea(){ return dim1 * dim2; }
	void setDim2(int inDim2){ dim2 = inDim2; }
};

class triangle : public shape{
private:
	double dim2;
public:
	double getArea(){ return dim1 * dim2 / 2; }
	void setDim1(int inDim1){ dim1 = inDim1; }
};

int main(array<System::String ^> ^args)
{
	shape s1;
	s1.setDim1(5);
	cout << "This is the area of what we just created: " << s1.getArea() << endl;
	
	shape * ptrBase;
	ptrBase = &s1;
	cout << ptrBase->getArea() << endl;

	system("pause");
	return 0;
}