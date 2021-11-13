// Section6_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//const double PI = 3.14159;

/*inline double sphereVolume(const double radius)
{
	return 4.0 / 3.0 * PI * pow(radius, 3);
}*/

/*bool multiple(int x, int y)
{
	if (y / x == 0)
	{
		return true;
	}
	return false;

}*/

int flip()
{
	int flipNum;
	flipNum = rand()%2+1;
	if (flipNum == 1)
		cout << "Heads" << endl;
	else
		cout << "Tails" << endl;
	return flipNum;
}

int main()
{
	//double radiusValue;
	//cout << multiple(2, 17) << endl;

	int flipTimes = 100;
	int times = 0;			//var to cout current time
	int face = 0;			//var to call flip
	int heads = 0;			//var to count up all heads
	int tails = 0;			//var to count up all tails

	srand(static_cast<int>(time(0))); //random num generator

	for (int times = 1; times <= flipTimes; times++)
	{
		face = flip();
		if (face == 1)
			heads++;
		else
			tails++;
	}

	cout << "The number flips: " << flipTimes << endl;
	cout << "The number of times heads came up: " << heads << endl;
	cout << "The number of times tails came up: " << tails << endl;

	//cout << "Enter the length of the radius of your sphere ";
	//cin >> radiusValue;

	//cout << "Volume of sphere with radius " << radiusValue << " is " << sphereVolume(radiusValue) << endl;
	cout << "Christian Anagnostou" << endl;
	system("pause");
}

