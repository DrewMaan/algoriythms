#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
	int max = 0;
	char str1[30] = { 0 };
	char str2[30] = { 0 };

	printf("Eneter first sequence: ");
	scanf("%s", &str1);
	printf("Eneter second sequence: ")
	scanf("%s", &str2);

	int n = strlen(str1) + 1;
	int m = strlen(str2) + 1;

	int** a;

	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)
		{
			a[i][j] = 0;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				a[i][j] = a[i - 1][j - 1] + 1;
				if (a[i][j] > max)
					max = a[i][j];
			}
			else
			{
				if (a[i - 1][j] >= a[i][j - 1])
					a[i][j] = a[i - 1][j];
				else
					a[i][j] = a[i][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("Max subsequence: %d\n", max);

	return 0;
}