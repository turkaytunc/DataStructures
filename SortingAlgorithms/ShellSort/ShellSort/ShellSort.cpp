#include "pch.h"
#include <iostream>

void ShellSort(int *intArray, int size);

int main()
{
    
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