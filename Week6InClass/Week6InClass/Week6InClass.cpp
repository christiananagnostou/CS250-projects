// Week6InClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//OVERLOADING - adding more with same name, but diff arg list
//OVERRIDING - replacing the name and the arg list (header is the same but the body is different)


//overloading
int fun() {
	return 0; 
}
int fun(int x){				//pass by value - copy from input var to arg var.{
	return x;
}
int fun(int x, double d){
	return x + d;
}
int fun(double d, int x){
	return x + d;
}

//overriding in a class only
/*int fun(double d, int x){
	return x * d;
}*/


int fun(int * ptrArray)
{
	return 0; 
}
//step 1 - define the new datatype
class myClass
{
private: //must access using a function
	char gender;
	int x;
public:  //access using dot notation in step 3
	//or a constructor function called in step 2
	myClass(){ gender = 'U';}
	myClass(char inGender){ gender = inGender; }
	char getGender(){ return gender; }
	void setGender(char inGender){ gender = inGender; }
	char get(){ return x; }
	void set(char inX){ x = inX; }

};
int main()
{
	//step 3 - use it
	//declare a new instance of the new class
	myClass O1;	//default constructor
	cout << O1.getGender() << endl;

	myClass O2('M');	//paramaterized constructor
	cout << O2.getGender() << endl;



	int myArray[10] = { 0 };
	int * pointerVar = myArray;
	cout << fun(pointerVar) << endl;

	 
	cout << myArray << endl;
	cout << &myArray << endl;
	cout << &myArray[0] << endl;

	//cout << fun << endl;	//cant use this when overloaded
	//cout << &fun << endl;
	cout << fun() << endl;

	system("pause");

	return 0;
}

