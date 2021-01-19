#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define T int
#define SIZE_QUEUE 64

T QueueArr[SIZE_QUEUE];
int tail = -1;
int head = -1;

struct Node
{
	int number;
	struct Node* nextPtr;
};

struct Queue
{
	struct Node* list;
	struct Node* head;
	struct Node* tail;
};

struct Queue QueueList;

void EnqueueArr(int);
int DequeueArr();
void Enqueue(int);
struct Node* Dequeue();
struct Node* Add(struct Node*, int);

int main()
{
	struct Node* n;

	srand(time(NULL));

	printf("Queue array:\n");
	printf("Add to queue: \n");
	for (int i = 0; i < 15; i++)
	{
		int e = rand() % 50;
		EnqueueArr(e);
		printf("Add %d\n", e);
	}

	printf("Queue from head to tail:\n");
	while (tail != head)
	{
		printf("%d ", DequeueArr());
	}
	printf("\n\n\n");

	printf("Queue list:\n");
	printf("Add to queue: \n");
	for (int i = 0; i < 15; i++)
	{
		int e = rand() % 50;
		Enqueue(e);
		printf("Add %d\n", e);
	}

	printf("Queue from head to tail:\n");
	while (QueueList.tail != NULL)
	{
		n = Dequeue();
		printf("%d ", n->number);
	}
	printf("\n\n\n");
}

void EnqueueArr(int element)
{
	if (tail == -1)
	{
		tail = 0;
		QueueArr[tail] = element;
	}
	else if (tail != -1 && tail < SIZE_QUEUE)
	{
		tail++;
		QueueArr[tail] = element;
	}
	else
	{
		int indexTail = tail - SIZE_QUEUE;
		if (indexTail < head)
		{
			tail = indexTail;
			QueueArr[tail] = element;
		}
		else
		{
			printf("Queue overflow\n");
		}
	}
}

int DequeueArr()
{
	if (head == tail)
	{
		printf("Queue is empty\n");
	}
	else
	{
		head++;
		if (head >= SIZE_QUEUE)
		{
			head = (SIZE_QUEUE - head) * -1;
			int element = QueueArr[head];
			QueueArr[head] = 0;
			return element;
		}
		else
		{
			int element = QueueArr[head];
			QueueArr[head] = 0;
			return element;
		}
	}
}

void Enqueue(int numb)
{
	if (QueueList.tail == NULL)
	{
		QueueList.list = Add(QueueList.list, numb);
		QueueList.head = QueueList.list;
		QueueList.tail = QueueList.list;
	}
	else
	{
		QueueList.list = Add(QueueList.list, numb);
		QueueList.tail = QueueList.list;
	}
}

struct Node* Dequeue()
{
	struct Node* returnNode = (struct Node*)malloc(sizeof(struct Node));

	if (QueueList.head == NULL && QueueList.tail == NULL)
	{
		printf("Queue is empty\n");
	}
	else if (QueueList.head == QueueList.tail)
	{
		returnNode->number = QueueList.head->number;
		QueueList.tail = NULL;
		free(QueueList.head);
		QueueList.head = NULL;
		return returnNode;
	}
	else
	{
		returnNode->number = QueueList.head->number;
		struct Node* deleteNode = QueueList.head;
		QueueList.head = QueueList.head->nextPtr;
		free(deleteNode);
		return returnNode;
	}
}

struct Node* Add(struct Node* el, int n)
{
	struct Node* newNode, * ptr;
	newNode = (struct Node*)malloc(sizeof(struct Node));

	if (el == NULL)
	{
		newNode->number = n;
		newNode->nextPtr = NULL;
		return newNode;
	}
	else
	{
		ptr = el->nextPtr;
		el->nextPtr = newNode;
		newNode->number = n;
		newNode->nextPtr = ptr;
		return newNode;
	}
}