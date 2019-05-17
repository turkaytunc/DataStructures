#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>


int top = -1;
char stack[13];

void push(char x)
{
	top = top + 1;
	stack[top] = x;

}
void pop(char t)
{
	if (t == '}')
	{
		if (stack[top] == '{')
			top = top - 1;

	}
	else if (t == ')')
	{
		if (stack[top] == '(')
			top = top - 1;
	}
	else if (t == ']')
	{

		if (stack[top] == '[')
			top = top - 1;
	}


}

int main()
{

	_getch();
}