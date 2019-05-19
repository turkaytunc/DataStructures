#include "pch.h"
#include <iostream>

void SelectionSort(int *arr, int size);

int main()
{
    
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