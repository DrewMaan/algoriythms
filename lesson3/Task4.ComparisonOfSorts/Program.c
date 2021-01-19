#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>

#define SIZE_ARR 10

int BubbleSort(int[], int);
int BubbleSortModified(int[], int);
int ShakerSort(int[], int);
int InsertSort(int[], int);
int MergeSort(int[], int, int);
void Swap(int*, int*);
void PrintArr(int[], int);
void Merge(int[], int, int, int, int*);

int main()
{
	int originalArr[SIZE_ARR] = { 0 };
	int sortArrBS[SIZE_ARR] = { 0 };
	int sortArrBSM[SIZE_ARR] = { 0 };
	int sortArrShS[SIZE_ARR] = { 0 };
	int sortArrIS[SIZE_ARR] = { 0 };
	int sortArrMS[SIZE_ARR] = { 0 };
	int Count = 0;

	srand(time(NULL));

	for (int i = 0; i < SIZE_ARR; i++)
	{
		originalArr[i] = (rand() % SIZE_ARR) + 1;
		sortArrBS[i] = originalArr[i];
		sortArrBSM[i] = originalArr[i];
		sortArrShS[i] = originalArr[i];
		sortArrIS[i] = originalArr[i];
		sortArrMS[i] = originalArr[i];
	}
	PrintArr(originalArr, SIZE_ARR);

	Count = BubbleSort(sortArrBS, SIZE_ARR);
	printf("Number comparisons bubble sorting: %d\n", Count);
	PrintArr(sortArrBS, SIZE_ARR);

	Count = BubbleSortModified(sortArrBSM, SIZE_ARR);
	printf("Number comparisons bubble sorting modified: %d\n", Count);
	PrintArr(sortArrBSM, SIZE_ARR);

	Count = ShakerSort(sortArrShS, SIZE_ARR);
	printf("Number comparisons shaker sorting: %d\n", Count);
	PrintArr(sortArrShS, SIZE_ARR);

	Count = InsertSort(sortArrIS, SIZE_ARR);
	printf("Number comparisons insert sorting: %d\n", Count);
	PrintArr(sortArrIS, SIZE_ARR);

	Count = MergeSort(sortArrMS, 0, SIZE_ARR - 1);
	printf("Number comparisons merge sorting: %d\n", Count);
	PrintArr(sortArrMS, SIZE_ARR);
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

int InsertSort(int a[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		int temp = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > temp)
		{
			count++;
			Swap(&a[j], &a[j - 1]);
			j--;
		}
	}

	return count;
}

int MergeSort(int a[], int start, int end)
{
	int* count = (int*)malloc(sizeof(int));
	*count = 0;

	if (start + 1 >= end) return;
	int mid = start + (end - start) / 2;

	MergeSort(a, start, mid);
	MergeSort(a, mid, end);

	Merge(a, start, end, mid, &count);

	return count;
}

void Swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void Merge(int a[], int start, int end, int middle, int* c)
{
	int it1 = 0;
	int it2 = 0;
	int count = 0;

	int* result = (int*)malloc((end - start) * sizeof(int));

	while (start + it1 < middle && middle + it2 < end)
	{
		count++;
		if (a[start + it1] < a[middle + it2])
		{
			count++;
			result[it1 + it2] = a[start + it1];
			it1++;
		}
		else
		{
			count++;
			result[it1 + it2] = a[middle + it2];
			it2++;
		}
	}

	while (start + it1 < middle)
	{
		count++;
		result[it1 + it2] = a[start + it1];
		it1++;
	}

	while (middle + it2 < end)
	{
		count++;
		result[it1 + it2] = a[middle + it2];
		it2++;
	}

	for (int i = 0; i < it1 + it2; i++)
	{
		count++;
		a[start + i] = result[i];
	}

	*c = count;
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