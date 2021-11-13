// Week6Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm> // std::min_element
#include <iterator>  // std::begin, std::end
using namespace std;

class bubbleSort
{
public:
	void sort(int myArr[])
	{
		int smallerNum = -1;
		int length = 10;			//length of the array

		for (int count = length - 1; count > 0; count--)	//loop through the array until down to the first number from last
		{
			for (int x = 0; x < 9; x++)			//loops through the numbers in the array
			{
				if (myArr[x] > myArr[x + 1])		//checks if second is smaller than the first
				{
					smallerNum = myArr[x + 1];			//save the smaller number
					myArr[x + 1] = myArr[x];			//swap smaller with bigger
					myArr[x] = smallerNum;
				}

			}
		}
		for (int x = 0; x < 10; x++)
		{
			cout << myArr[x] << " ";
		}
		cout << endl;
	}
};


class Palindrome
{
public:
	Palindrome(){};
	bool testPalindrome(string s)
	{
		int length = s.length() - 1;	//last letter in string
		for (int index = 0; index <= length / 2; index++)	//loop up to the middle of the string
			if (s[index] != s[length - index])	//check if index is equal to the index of the other side of the string
			{
			return false;
			}
		return true;
	}
	void answer(string t)
	{
		
		if (testPalindrome(t) == 0)
		{
			cout << "This is not a palindrome." << endl;
		}
		else
		{
			cout << "This is a palindrome." << endl;
		}
	}
};
class minVector
{
public:
	void minimumValue(std::vector<int> &v)
	{
		auto result = std::min_element(std::begin(v), std::end(v));
		if (std::end(v) != result)
			std::cout << *result << '\n';
	}
};

int main()
{

	minVector v1;
	vector<int> v = { 5, 14, 2, 4, 6 };
	v1.minimumValue(v);

	//cout << "___________________________" << endl;

	Palindrome p1;
	string test = "totally";		//should return false
	string test2 = "the dog ran nar god eht";	//should return true
	//p1.answer(test);

	//cout << "___________________________" << endl;

	bubbleSort sort1;
	int myArray[] = { 5, 12, 65, 2, 984, 156, 58, 4651, 42, 26 };
	//sort1.sort(myArray);


	cout << "Christian Anagnostou"<< endl;
	system("pause");
	return 0;
}

