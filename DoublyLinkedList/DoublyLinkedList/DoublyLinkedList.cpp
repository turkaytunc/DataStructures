#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

struct Node
{
	int age;
	char name[10];
	char surname[10];

	struct Node *next = NULL;
	struct Node *prev = NULL;
};

struct Node *head = NULL;
struct Node *end = NULL;
struct Node *current = NULL;


void Insert(int, char *, char *);
void PrintList();
void ReversePrintList();
void WriteToFile();
struct Node*  DeleteListItem(int);
void Menu(char key);

int main()
{
	char choice = ' ';
	while (choice != '0')
	{
		printf("1 Insert\t 2 PrintList\t3 ReversePrintList\t4 WriteToFile\t5 DeleteListItem\t0 Exit:\n");
		choice = _getch();
		Menu(choice);
	}
	return 0;
}

void Insert(int age, char *name, char *surname)
{
	struct Node *p = (struct Node *)malloc(sizeof(struct Node));

	p->age = age;
	strncpy_s(p->name, name, 10);
	strncpy_s(p->surname, surname, 10);

	if (head == NULL)
	{
		end = head = p;
		head->prev = NULL;
		head->next = end;
		end->next = NULL;
	}
	else if (head->next == NULL)
	{
		head->next = p;
		end = p;
		p->next = NULL;
		end->next = NULL;
		end->prev = head;

	}
	else
	{
		end->next = p;
		p->prev = end;
		end = p;
		end->next = NULL;
	}
	end = p;
}

void ReversePrintList()
{
	struct Node *p = (struct Node *)malloc(sizeof(struct Node));
	p = end;

	while (p != NULL)
	{
		printf("%d %s %s", p->age, p->name, p->surname);
		printf("\n");
		p = p->prev;
	}
}
void PrintList()
{
	struct Node *p = (struct Node *)malloc(sizeof(struct Node));
	p = head;
	while (p != NULL)
	{
		printf("%d %s %s", p->age, p->name, p->surname);
		printf("\n");
		p = p->next;
	}
}

void WriteToFile()
{
	struct Node *p = (struct Node *)malloc(sizeof(struct Node));
	FILE *fp = fopen("arc.txt", "a+");
	p = head;

	while (p != NULL)
	{

		fprintf(fp, p->name);
		fprintf(fp, " ");
		fprintf(fp, p->surname);
		fprintf(fp, " ");
		fprintf(fp, "%d", p->age);
		fprintf(fp, "\n");

		p = p->next;

	}
	fclose(fp);
}

struct Node* DeleteListItem(int key)
{
	current = head;
	struct Node *previous = NULL;

	if (head == NULL)return NULL;

	while (current->age != key)
	{
		if (current->next == NULL)
		{
			return NULL;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}


	if (current == head)
		head = head->next;
	else
		current->prev->next = current->next;

	if (current == end)
	{
		end = current->prev;
	}
	else
	{
		current->next->prev = current->prev;
	}

	return current;
}

void Menu(char choice)
{
	char name[10];
	char surname[10];
	int age;
	int key;
	if (choice == '1')
	{


		printf("Name surname age: \n");
		scanf("%s", name);
		scanf("%s", surname);
		scanf("%d", &age);
		Insert(age, name, surname);

	}
	if (choice == '2')
	{

		system("cls");
		PrintList();
	}
	if (choice == '3')
	{
		system("cls");
		ReversePrintList();
	}
	if (choice == '4')
	{
		WriteToFile();
	}
	if (choice == '5')
	{
		printf("Delete: key\n");
		scanf("%d", &key);
		DeleteListItem(key);
	}
}




