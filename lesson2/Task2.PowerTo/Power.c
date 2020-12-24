/*
* 
*	Реализовать функцию возведения числа a в степень b:
*	a. без рекурсии;
*	b. рекурсивно;
*	c. *рекурсивно, используя свойство четности степени.
*
* Касимовский Андрей
*/

#include <stdio.h>

int PowerTo(int, int);
int RecPowerTo(int, int);
int RecPowerTo_ParityProp(int, int);

int main()
{
	int n, p;
	scanf_s("%d %d", &n, &p);

	printf("%d\n", PowerTo(n, p));
	printf("%d\n", RecPowerTo_ParityProp(n, p));
	printf("%d\n", RecPowerTo(n, p));
}

int PowerTo(int number, int power)
{
	int result = 1;
	for (int i = power; i > 0; i--)
	{
		result *= number;
	}

	return result;
}

int RecPowerTo(int number, int power)
{
	if (power == 1)
	{
		return number;
	}
	else
	{
		return number * RecPowerTo(number, power - 1);
	}
}

int RecPowerTo_ParityProp(int number, int power)
{
	if (power == 0)
	{
		return 1;
	}
	else if (power % 2 == 0)
	{
		return RecPowerTo_ParityProp(number * number, power / 2);
	}
	else
	{
		return number * RecPowerTo_ParityProp(number, power - 1);
	}
}