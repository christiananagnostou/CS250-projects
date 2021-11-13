// Week14Assignment.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace System;

template <typename T>
void selectionSort(T * const array, int size)
{
	int smallest;
	for (int i = 0; i < size - 1; ++i)
	{
		smallest = i;
		for (int index = i + 1; index < size; ++index)
		{
			if (array[index] < array[smallest])
				smallest = index;
			swap(&array[i], &array[smallest]);
		}
	}
}
template <typename L>
void swap(L *  element1Ptr, L * element2Ptr)
{
	L hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

int main()
{
	const int arraySize = 5;
	float a[arraySize] = { 2.98, 5.24, 6.7, 58.4, 15.46 };
	selectionSort(a, arraySize);
	for (int j = 0; j < arraySize; ++j)
	{
		cout << a[j] << " ";
	}
	cout << endl;
	int b[arraySize] = { 2, 5, 6, 58, 15 };
	selectionSort(b, arraySize);
	for (int j = 0; j < arraySize; ++j)
	{
		cout << b[j]<< " ";
	}
	cout << endl;
	system("pause");
    return 0;
}
