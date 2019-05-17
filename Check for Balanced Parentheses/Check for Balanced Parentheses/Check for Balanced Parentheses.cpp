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
void display()
{
	int i;
	if (top == -1)
		printf("stack empty\n balanced paranthesis\n");
	else
	{

		for (i = 0; i <= top; i++)
			printf("\t %c", stack[i]);
	}
}
int main()
{
	
	_getch();
}