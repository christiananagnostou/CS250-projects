// 2.27 Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;						 //allows input and output


int _tmain(int argc, _TCHAR* argv[])
{
	char input;								//create a variable to hold input
	std:cout << "Enter a character:";		//promp user to input char
	cin >> input;							//recieve input
	cout << static_cast<int>(input);		//print input as an int
	system("Pause");
}
