#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void InsertionSort(int *arr, int size);
void PrintArray(int *arr, int size);

int main()
{

	int A[10] = { 5,-1,0,3,7,1,5,103,87,90 };

	PrintArray(A, 10);

	InsertionSort(A, 10);
	PrintArray(A, 10);

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

void PrintArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
