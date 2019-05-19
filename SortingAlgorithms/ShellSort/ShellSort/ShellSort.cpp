#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void PrintArray(int *arr, int size);
void ShellSort(int *intArray, int size);

int main()
{
	int A[11] = { 5,-1,0,3,7,1,7,0,21,34,6 };

	PrintArray(A, 11);

	ShellSort(A, 11);
	PrintArray(A, 11);


	char ch = ' ';
	cin >> ch;
}

void ShellSort(int *intArray, int size)
{
	int inner, outer;
	int valueToInsert;
	int interval = 1;
	int elements = size;
	int i = 0;

	while (interval <= elements / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (outer = interval; outer < elements; outer++)
		{
			valueToInsert = intArray[outer];
			inner = outer;

			while (inner > interval - 1 && intArray[inner - interval] >= valueToInsert)
			{
				intArray[inner] = intArray[inner - interval];
				inner -= interval;
			}
			intArray[inner] = valueToInsert;
		}
		interval = (interval - 1) / 3;
		i++;
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