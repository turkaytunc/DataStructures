#include "pch.h"
#include <iostream>
#define MAX_SIZE 50 

using std::cout;
using std::cin;
using std::endl;

class Stack
{
private:
	int A[MAX_SIZE];
	int top;   
public:
	// constructor
	Stack()
	{
		top = -1; 
	}

	// Push operation to insert an element on top of stack. 
	void Push(int x)
	{
		if (top == MAX_SIZE - 1)
		{
			cout << ("Error: stack overflow\n");
			return;
		}
		A[++top] = x;
	}

	// Pop operation to remove an element from top of stack.
	void Pop()
	{
		if (top == -1)
		{
			cout << ("Error: No element to pop\n");
			return;
		}		
		top--;
	}

	
};

int main()
{
	char ch = ' ';
	Stack *stack = new Stack();

	stack->Push(5);
	

	cin >> ch;
}
