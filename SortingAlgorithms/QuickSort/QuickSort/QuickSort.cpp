#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void PrintArray(int *arr, int size);
void Swap(int &x, int &y);
int Partition(int *, int, int);
void QuickSort(int *, int, int);

int main()
{
	int A[7] = { 5,-1,0,3,7,1,5 };

	PrintArray(A, 7);

	QuickSort(A, 0, 6);
	PrintArray(A, 7);


	char ch = ' ';
	cin >> ch;
}


int Partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int pIndex = start;
	
	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			Swap(arr[pIndex], arr[i]);
			pIndex++;
		}
	}
	Swap(arr[pIndex], arr[end]);
	return pIndex;
}

void PrintArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void QuickSort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pIndex = Partition(arr, start, end);
		QuickSort(arr, start, pIndex - 1);
		QuickSort(arr, pIndex + 1, end);
	}
}