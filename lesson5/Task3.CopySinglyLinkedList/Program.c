#include <stdio.h>

struct Node
{
	int age;
	char name[20];

	struct Node* nextPtr;
};

void AddName(char[], char);
struct Node* InitList();
struct Node* Add(struct Node*, int, char);
struct Node* Copy(struct Node*);
void CopyName(char[], char[]);
void PrintList(struct Node*);

int main()
{
	struct Node* list;
	struct Node* copyList;
	list = InitList();
	copyList = Copy(list);

	printf("Originally list:\n");
	PrintList(list);
	printf("\n\n");
	printf("Copy list list:\n");
	PrintList(copyList);

	return 0;
}

struct Node* InitList()
{
	struct Node* elem = (struct Node*)malloc(sizeof(struct Node));
	elem->age = 10;
	AddName(elem->name, 'A');
	elem->nextPtr = NULL;

	struct Node* temp = elem;

	for (int i = 1; i < 5; i++)
	{
		int ag = i * 10;
		temp = Add(temp, ag, (char)((int)'A' + i));
	}
	
	return elem;
}

struct Node* Add(struct Node* node, int a, char n)
{
	struct Node* newNode, *ptr;
	newNode = (struct Node*)malloc(sizeof(struct Node));

	ptr = node->nextPtr;
	node->nextPtr = newNode;
	newNode->age = a;
	AddName(newNode->name, n);
	newNode->nextPtr = ptr;

	return newNode;
}

struct Node* Copy(struct Node* list)
{
	struct Node* firstElem = (struct Node*)malloc(sizeof(struct Node));
	firstElem->age = list->age;
	CopyName(firstElem->name, list->name);
	firstElem->nextPtr = NULL;
	if (list->nextPtr == NULL)
		return firstElem;
	else
		list = list->nextPtr;

	struct Node* elem = firstElem;
	
	do
	{
		elem = Add(elem, list->age, list->name[0]);
		list = list->nextPtr;
	} while (list != NULL);

	return firstElem;
}

void AddName(char nm[], char cc)
{
	for (int i = 0; i < 20; i++)
	{
		nm[i] = cc;
	}
}

void CopyName(char c1[], char c2[])
{
	for (int i = 0; i < 20; i++)
	{
		c1[i] = c2[i];
	}
}

void PrintList(struct Node* list)
{
	do
	{
		printf("Address node: %p\n", list);
		printf("Age: %d, name: %c\n", list->age, list->name[0]);
		printf("\n");
		list = list->nextPtr;
	} while (list != NULL);
}