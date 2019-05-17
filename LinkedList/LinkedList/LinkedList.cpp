#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class Node
{
public:
	 int data;
	 Node *next;
};

Node *current = NULL;

void InsertFirst(Node **head, int data);
void InsertLast(Node **head, int data);
void PrintList(Node **head);
void DeleteItem(Node **head, int n);
void DeleteItem(int key, Node **head);
void ReverseListIterative(Node **head);
void ReverseListRecursive(Node **head);

int main()
{
	Node *head = NULL;

	char ch;
	int data = 0;
	int n = 0;

	while (data != -1)
	{
		cin >> data;
		if (data == -1)break;
		InsertLast(&head,data);
		system("cls");
		PrintList(&head);
	}

	ReverseListIterative(&head);
	PrintList(&head);
	ReverseListIterative(&head);
	PrintList(&head);
	
	cout << "Delete item at index \n";
	cin >> n;
	DeleteItem(&head, n);
	PrintList(&head);

	DeleteItem(5, &head);
	PrintList(&head);


	cin >> ch;
}

//Insert new data to beginning of the list
void InsertFirst(Node **head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;

	temp->next = *head;
	*head = temp;
}
//Insert item in the end of the list
void InsertLast(Node **head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	current = *head;

	//if there is no data in LinkedList, temp is the new head
	if (*head == NULL) *head = temp;

	//iterate through last node and insert new node
	else
	{
		while (current->next != NULL) current = current->next;
		current->next = temp;
	}
}
//Delete item at n. position
void DeleteItem(Node **head, int n)
{
	current = *head;
	Node *prev = current;

	if (n == 1)
	{
		*head = current->next;
		
		delete current;
		return;
	}
	else if (n > 1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			prev = current;
			current = current->next;
		}
		if (current != NULL)
		{
			prev->next = current->next;
			delete current;
		}
	}

}
//Delete item by value
void DeleteItem(int key, Node ** head)
{
	current = *head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		if (current->data == key)
		{
			DeleteItem(head, count);
			return;
		}
		current = current->next;
	}
}
//Reverse list
void ReverseListIterative(Node **head)
{
	Node *prev, *next = NULL;
	prev = NULL;
	current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;

	delete next,prev;
}

void ReverseListRecursive(Node **head)
{

}
//Print items in the list
void PrintList(Node **head)
{
	current = *head;

	while (current != NULL)
	{
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}
