#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE_ARR 100

/*
* 
* Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и неоптимизированной программы. 
* Написать функции сортировки, которые возвращают количество операций.
* 
* Выполнил: Касимовский Андрей
* 
*/

int BubbleSort(int[], int);
int BubbleSortModified(int[], int);
void Swap(int*, int*);
void PrintArr(int[], int);

int main()
{
	int originalArr[SIZE_ARR] = { 0 };
	int sortArrBS[SIZE_ARR] = { 0 };
	int sortArrBSM[SIZE_ARR] = { 0 };
	int Count = 0;

	srand(time(NULL));

	for (int i = 0; i < SIZE_ARR; i++)
	{
		originalArr[i] = (rand() % SIZE_ARR) + 1;
		sortArrBS[i] = originalArr[i];
		sortArrBSM[i] = originalArr[i];
	}
	PrintArr(originalArr, SIZE_ARR);

	Count = BubbleSort(sortArrBS, SIZE_ARR);
	printf("Number comparisons bubble sorting: %d\n", Count);
	PrintArr(sortArrBS, SIZE_ARR);

	Count = BubbleSortModified(sortArrBSM, SIZE_ARR);
	printf("Number comparisons bubble sorting modified: %d\n", Count);
	PrintArr(sortArrBSM, SIZE_ARR);

	return 0;
}

int BubbleSort(int a[], int size)
{
	int count = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			count++;
			if (a[j] > a[j + 1])
			{
				count++;
				Swap(&a[j], &a[j + 1]);
			}
		}
	}

	return count;
}

int BubbleSortModified(int a[], int size)
{
	int count = 0;
	int countComparisons;

	for (int i = 0; i < size; i++)
	{
		countComparisons = 0;
		for (int j = size - 1; j > i; j--)
		{
			count++;
			if (a[j - 1] > a[j])
			{
				count++;
				Swap(&a[j - 1], &a[j]);
				countComparisons++;
			}
		}
		if (countComparisons == 0) break;
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