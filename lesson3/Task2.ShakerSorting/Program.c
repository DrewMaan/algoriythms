#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE_ARR 100

/*
*
* *Реализовать шейкерную сортировку.
*
* Выполнил: Касимовский Андрей
*
*/

int ShakerSort(int[], int);
void Swap(int*, int*);
void PrintArr(int[], int);

int main()
{
	int originalArr[SIZE_ARR] = { 0 };
	int Count = 0;

	srand(time(NULL));

	for (int i = 0; i < SIZE_ARR; i++)
	{
		originalArr[i] = (rand() % SIZE_ARR) + 1;
	}
	PrintArr(originalArr, SIZE_ARR);

	Count = ShakerSort(originalArr, SIZE_ARR);
	printf("Number comparisons shaker sorting: %d\n", Count);
	PrintArr(originalArr, SIZE_ARR);

	return 0;
}

int ShakerSort(int a[], int size)
{
	int left = 0;
	int right = size - 1;
	int count = 0;

	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			count++;
			if (a[i] > a[i + 1])
			{
				count++;
				Swap(&a[i], &a[i + 1]);
			}
		}
		right--;

		for (int i = right; i > left; i--)
		{
			count++;
			if (a[i - 1] > a[i])
			{
				count++;
				Swap(&a[i - 1], &a[i]);
			}
		}
		left++;
	}

	return count;
}

void Swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
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