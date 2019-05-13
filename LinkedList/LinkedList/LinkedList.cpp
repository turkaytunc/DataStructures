#include "pch.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


struct Node
{
	int data;
	Node *next;
};

Node *current = NULL;

void InsertFirst(Node **head, int data);
void InsertLast(Node **head, int data);
void PrintList(Node **head);
void DeleteListItem(Node **head, int n);

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
	cout << "Delete item at index \n";
	cin >> n;
	DeleteListItem(&head, n);
	PrintList(&head);
	cin >> ch;
}

//insert new data to beginning of list
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
void DeleteListItem(Node **head, int n)
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


