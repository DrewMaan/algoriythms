#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define T char
#define SIZE_STACK 64

T Stack[SIZE_STACK];
int tail = -1;

void Push(T);
T Pop();
void InfixToPostfix(char[], char[]);
void PrintCharArr(char[], int);

int main()
{
	char* infix = (char*)malloc(64);
	char postfix[64] = { '\0' };

	//gets_s(infix, 64);

	infix = "(a + b) * c - (d - e) * (f + g)";

	InfixToPostfix(infix, postfix);

	PrintCharArr(postfix, 64);
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
		T op = Stack[tail];
		Stack[tail] = 0;
		tail--;
		return op;
	}
	else
	{
		printf("Stack is empty!");
	}
}

void InfixToPostfix(char in[], char post[])
{
	int i = 0;
	int j = 0;
	while (in[i] != '\0')
	{
		if (isalpha(in[i]) || isalnum(in[i]))
		{
			post[j] = in[i];
			j++;
			i++;
			continue;
		}
		if (in[i] == '(')
			Push(in[i]);
		if (in[i] == '*' || in[i] == '/')
			Push(in[i]);
		if (in[i] == ')')
		{
			char op = Pop();
			while (op != '(')
			{
				post[j] = op;
				op = Pop();
				j++;
			}
		}
		if (in[i] == '+' || in[i] == '-')
		{
			if (tail != -1)
			{
				char op = Pop();
				while (op == '*' || op == '/')
				{
					post[j] = op;
					if (tail == -1)
						j++;
						break;
					op = Pop();
					j++;
				}
				if (op == '(' || op == '+' || op == '-')
				{
					Push(op);
					Push(in[i]);
				}
				else
					Push(in[i]);
			}
			else
			{
				Push(in[i]);
			}
		}
		i++;
	}

	while (tail != -1)
	{
		post[j] = Pop();
		j++;
	}
	post[j] = '\0';
}

void PrintCharArr(char arr[], int size)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}