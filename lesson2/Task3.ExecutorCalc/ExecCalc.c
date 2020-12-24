/*
* 
*	Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
*
*		Прибавь 1
*		Умножь на 2
*
*	Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20?
*		а) с использованием массива;
*		б) с использованием рекурсии.
*
*
*	Касимовский Андрей
*/

#include <stdio.h>

void CountWay(int, int, int*);

int main()
{
	const int start = 3;
	const int end = 20;
	int arr[21] = {0};
	int count = 0;

	arr[start] = 1;

	for (int i = start + 1; i <= end; i++)
	{
		if (i > 0)
		{
			if (i % 2 == 0)
			{
				arr[i] = arr[i - 1] + arr[i / 2];
			}
			else
			{
				arr[i] = arr[i - 1];
			}
		}
	}

	printf("%d\n", arr[end]);

	CountWay(start, end, &count);

	printf("%d\n", count);
}

void CountWay(int s, int e, int* c)
{
	if (s == e)
	{
		*c = *c + 1;
	}
	else if (s > e)
	{
		return;
	}
	else
	{
		CountWay(s + 1, e, c);
		CountWay(s * 2, e, c);
	}
}