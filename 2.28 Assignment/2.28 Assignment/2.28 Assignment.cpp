// 2.28 Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;							//allows an input from the user


int _tmain(int argc, _TCHAR* argv[])
{
	int input;									//creates a variable to hold input
	std:cout << "Enter a five-digit integer:";	//promp user to input char
	cin >> input;								//recieve input
	int num1 = input % 10;						//stores the numbers individually
	int num2 = input/10 % 10;
	int num3 = input/100 % 10;
	int num4 = input/1000 % 10;
	int num5 = input/10000 % 10;
	string answer = (num1,"___",num2,"___",num3,"___",num4,"___",num5);
	system("Pause");
}
