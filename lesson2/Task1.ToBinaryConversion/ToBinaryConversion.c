/*
* Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию
* 
* Касимовский Андрей
*/

#include <stdio.h>

void MyConv(int);

int main()
{
	int n;
	printf("Введите число: ");
	scanf_s("%d", &n);

	MyConv(n);

	return 0;
}

void MyConv(int number)
{
	if (number < 0)
	{
		printf("-");
		MyConv(-number);
	}
	else if (number < 2)
	{
		printf("%d", number);
		return;
	}
	else
	{
		MyConv(number / 2);
		printf("%d", number % 2);
		return;
	}
}