#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

#define T char
#define SIZE_STACK 64

T Stack[SIZE_STACK];
int tail = -1;

void Push(T);
T Pop();
int CheckSequenceOfBrackets(char*);

int main()
{
	char* str = (char*)malloc(128);

	gets_s(str, 128);

	if (CheckSequenceOfBrackets(str))
		printf("Success!\n");
	else
		printf("Fail\n");

	return 0;
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
	if (tail != -1)
	{
		return Stack[tail--];
	}
	else
	{
		printf("Stack is empty!");
	}
}

int CheckSequenceOfBrackets(char* s)
{
	int length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Push(s[i]);
		else
		{
			if(s[i] != ')' && s[i] != ']' && s[i] != '}') 
				continue;
			if (tail == -1)
			{
				return 0;
			}
			char top = Pop();
			if ((top == '(' && s[i] != ')') || (top == '[' && s[i] != ']') || (top == '{' && s[i] != '}'))
				return 0;
		}
	}

	if (tail != -1)
	{
		return 0;
	}

	return 1;
}