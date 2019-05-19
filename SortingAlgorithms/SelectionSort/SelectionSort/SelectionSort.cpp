#include "pch.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

void PrintArray(int *arr, int size);
void SelectionSort(int *arr, int size);

int main()
{
	int A[7] = { 5,-1,0,3,7,1,7 };

	PrintArray(A, 7);

	SelectionSort(A, 7);
	PrintArray(A, 7);


	char ch = ' ';
	cin >> ch;
    
}

void SelectionSort(int *arr, int size)
{
	int indexMin, i, j;

	for (i = 0; i < size - 1; i++)
	{
		indexMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[indexMin])
			{
				indexMin = j;
			}
		}
		if (indexMin != i)
		{
			int temp = arr[indexMin];
			arr[indexMin] = arr[i];
			arr[i] = temp;
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