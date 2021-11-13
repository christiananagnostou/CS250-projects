// Thing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Thing.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Thing T1;
	Thing T2;
	Thing T3(42);
	T1.setHeight(11);
	cout << T1.getHeight() << endl;
	cout << T2.getHeight() << endl;
	cout << T3.getHeight() << endl;
	system("pause");
}