// Week8InClassAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myClass.h"
#include <iostream>

using namespace std;



int main()
{
	//step 2 - declare - this is where the constructor is called
	myClass C1;
		C1.setX(1);
	cout << "C1 x = " << C1.getX() << endl;
	myClass C2;
		C2.setX(2);
	cout << "C2 x = " << C2.getX() << endl;
	myClass C3;
		C3.setX(3);
	cout << "C3 x = " << C3.getX() << endl;

	
	cout << "C1 x = " << C1.getX() << endl;
	cout << "C2 x = " << C2.getX() << endl;
	cout << "C3 x = " << C3.getX() << endl;
	

	//step 3 - use it with the dot notation - public members only...
	system("pause");
	return 0;
}

