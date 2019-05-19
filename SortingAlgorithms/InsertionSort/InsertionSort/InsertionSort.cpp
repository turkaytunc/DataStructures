#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InsertionSort(int *arr, int size);


int main()
{


	char ch = ' ';
	cin >> ch;
}

void InsertionSort(int *arr, int size)
{
	int valueToInsert;
	int holePosition;
	int i;

	for (i = 1; i < size; i++)
	{
		valueToInsert = arr[i];
		holePosition = i;

		while (holePosition > 0 && arr[holePosition - 1] > valueToInsert)
		{
			arr[holePosition] = arr[holePosition - 1];
			holePosition--;
		}

		if (holePosition != i)
		{
			arr[holePosition] = valueToInsert;
		}

	}
}


