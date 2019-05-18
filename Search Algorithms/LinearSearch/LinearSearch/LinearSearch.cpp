#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void LinearSearch(int *arr, int size, int data);


int main()
{

	int A[5] = { 2,5,6,7,10 };

	LinearSearch(A, sizeof(A), 5);


	char ch = ' ';
	cin >> ch;
}

void LinearSearch(int *arr, int size, int data)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == data)
		{
			index = arr[i];
			printf("found at %d. index", i + 1);
		}
	}
	if (index == -1)
	{
		printf("Not found");
	}
}
