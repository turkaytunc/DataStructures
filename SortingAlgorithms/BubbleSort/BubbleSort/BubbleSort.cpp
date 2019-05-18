#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void BubbleSort(int *arr, int size);
void PrintArray(int *arr, int size);

int main()
{
	int A[7] = { 5,-1,0,3,7,1,5 };

	PrintArray(A, 7);

	BubbleSort(A, 7);
	PrintArray(A, 7);


	char ch = ' ';
	cin >> ch;
}

void BubbleSort(int * arr, int size)
{	
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
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
