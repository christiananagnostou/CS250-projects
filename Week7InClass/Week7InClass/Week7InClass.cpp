// Week7InClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void fun(int ptrArray[])
{
	cout << "Address of array IN the function: " << ptrArray << endl;
}

int main()
{
	int myArray[100] = { 0 };
	cout << "myArray address is: " << myArray << endl;
	fun(myArray);	//pass by reference
	
	int y = 12;
	//fun(y);		//pass by value
	
	int num = 42;
	int *ptrNum = &num;	//pointer
	cout << "using the pointer to prtNum: " << ptrNum << endl;
	
	int x; 
	x = 42;
	cout << "x = " << x << endl;
	cout << "Address of x = " << &x << endl;
	
	system("pause");
	return 0;
}

