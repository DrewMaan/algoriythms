#include <stdio.h>
#pragma warning(disable:4996)

#define T int
#define SIZE_STACK 64

T Stack[SIZE_STACK];
int tail = -1;

void Push(T);
T Pop();
int ConvertToBinary(int);
void PrintBinaryNumber();

int main()
{
	int number;

	printf("Enter number: ");
	scanf("%d", &number);

	ConvertToBinary(number);
	
	PrintBinaryNumber();
}

void Push(T i)
{
	if (tail < SIZE_STACK)
	{
		tail++;
		Stack[tail] = i;
	}
	else
	{
		printf("Stack overflow!");
	}
}

T Pop()
{
	if(tail != -1)
	{
		return Stack[tail--];
	}
	else
	{
		printf("Stack is empty!");
	}
}

int ConvertToBinary(int n)
{

	while (n != 0)
	{
		int d = n % 2;
		n /= 2;
		Push(d);
	}
}

void PrintBinaryNumber()
{
	while (tail != -1)
	{
		printf("%d", Pop());
	}
	printf("\n");
}