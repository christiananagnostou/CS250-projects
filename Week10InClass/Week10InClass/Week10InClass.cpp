// Week10InClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class myClass
{
private:
	int x;
public: 
	void setX(int intX){ x = intX; }
	int getX(){ return x; }
	void setXfromAnotherMyClass(myClass inO2)
	{
		this->x = inO2.x;
	}
	void operator+(myClass inO)
	{
		cout << "Sum = " << this->x + inO.x << endl;
	}
};
int main()
{
	myClass O1;
	O1.setX(42);
	cout << "O1 = " << O1.getX() << endl;

	myClass O2;
	O2.setX(13);
	cout << "O2 = " << O2.getX() << endl;

	O1.setXfromAnotherMyClass(O2);
	cout << "O1 = " << O1.getX() << endl;

	O1 + O2;

	system("pause");
	return 0;
}

