#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE_ARR 100

/*
*
* Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
* Функция возвращает индекс найденного элемента или -1, если элемент не найден.
*
* Выполнил: Касимовский Андрей
*
*/

void PrintArr(int[], int);
int BinarySearch(int[], int, int);

int main()
{
	int originalArr[SIZE_ARR] = { 0 };
	int oneElArr[1] = { 24 };
	int twoElArr[2] = { 24, 25 };
	int threeElArr[3] = { 24, 25, 27 };

	for (int i = 0; i < SIZE_ARR; i++)
	{
		originalArr[i] = i * i;
	}
	PrintArr(originalArr, SIZE_ARR);

	printf("Index number of 24: %d", BinarySearch(threeElArr, 3, 26));

	return 0;
}

void PrintArr(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("[%d] %d   ", i, a[i]);
		if (i % 10 == 0 && i != 0) printf("\n");
	}
	printf("\n\n\n");
}

int BinarySearch(int a[], int size, int n)
{
	int left = 0;
	int right = size - 1;
	int middle;

	if (size == 0) return -1;
	else if (size == 1)
	{
		if (a[0] == n) return 0;
	}
	else if (size == 2)
	{
		if (a[0] == n) return 0;
		else if (a[1] == n) return 1;
	}
	else
	{
		while (left <= right)
		{
			middle = left + (right - right) / 2;
			if (a[middle] == n)
				return middle;
			else if (a[middle] > n)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}
	}

	return -1;
}