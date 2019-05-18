#include "pch.h"
#include <iostream>

using std::cin;
using std::cout;


void BinarySearch(int *arr, int size, int data);

int main()
{

	int arr[10] = { 5,6,7,80,81,83,85,90,98,102 };


	BinarySearch(arr, sizeof(arr), 99);

	char ch = ' ';
	cin >> ch;
}


void BinarySearch(int *arr, int size, int data)
{

	int top = size, index = -1;
	int bot = 0, mid = 0;

	while (bot <= top)
	{
		mid = bot + (top - bot) / 2;

		if (arr[mid] == data)
		{
			index = arr[mid];
			printf("Found at %d. index", mid + 1);
			break;
		}
		else
		{
			if (arr[mid] < data)bot = mid + 1;
			else	
				top = mid - 1;
		}
	}
	if (index == -1)
	{
		printf("Not Found\n");
	}
}

