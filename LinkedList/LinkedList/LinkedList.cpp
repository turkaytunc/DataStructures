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

Node *head = NULL;
Node *current = NULL;

void InsertFirst(int data);
void InsertLast(int data);
void PrintList();


int main()
{
	char ch;
	int data = 0;



	while (data != -1)
	{
		cin >> data;
		if (data == -1)break;
		InsertFirst(data);
		system("cls");
		PrintList();
	}


	cin >> ch;
}

//insert new data to beginning of list
void InsertFirst(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;

	temp->next = head;
	head = temp;
}

void InsertLast(int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;

	current = head;

	//if there is no data in LinkedList, temp is the new head
	if (head == NULL) head = temp;


	//iterate through last node and insert new node
	else
	{
		while (current->next != NULL) current = current->next;

		current->next = temp;
	}
}

//start with head  , until current node is not empty print node's data
void PrintList()
{
	current = head;

	while (current != NULL)
	{
		cout << current->data << " -> ";
		current = current->next;
	}

	cout << "NULL\n";

}


