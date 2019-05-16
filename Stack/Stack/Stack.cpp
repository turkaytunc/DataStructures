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

	// Top operation to return element at top of stack. 
	int Top()
	{
		return A[top];
	}

	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
		if (top == -1) return 1;
		return 0;
	}
	// This will print all the elements in the stack at any stage. 
	void Print()
	{
		int i;
		cout << ("Stack: ");
		for (i = 0; i <= top; i++)
			cout << ("%d ", A[i]);
		cout << ("\n");
	}
};

int main()
{
	char ch = ' ';
	Stack *stack = new Stack();

	stack->Push(5);
	cout << stack->IsEmpty() << endl;
	stack->Print();

	cin >> ch;
}
