#include <stdio.h>
#include <ctype.h>

int ReadMap(int[][10]);
void PrintMap(int[][10]);
void FindNumbersWays(int[][10], int, int);

int main()
{
	int map[10][10] = { 0 };
	int startX, startY;
	int start;

	if (!ReadMap(map))
		return 0;
	PrintMap(map);

	printf("Введите точку старта: ");

	do
	{
		scanf_s("%d %d", &startX, &startY);
		if (startX <= 0 && startX > 10 && startY <= 0 && startY > 10)
		{
			start = 0;
		}
		else
		{
			start = map[startX - 1][startY - 1];
		}

		if (start == 0)
		{
			printf("Выберите другую точку старта: ");
		}
	} while (start == 0);

	FindNumbersWays(map, startX - 1, startY - 1);

	return 0;
}

int ReadMap(int m[][10])
{
	FILE* f;
	fopen_s(&f, "map.txt", "r+");

	if (f == NULL)
	{
		printf("Не удалось открыть файл\n");
		return 0;
	}
	else
	{
		int i = 0;
		int j = 0;
		while (!feof(f))
		{
			char c;
			fscanf_s(f, "%c", &c);
			if (isdigit(c))
			{
				m[i][j] = (int)c - (int)'0';
				j++;
			}
			else if (c == '\n')
			{
				i++;
				j = 0;
			}
			else
			{
				continue;
			}
		}

		return 1;
	}
}

void PrintMap(int m[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d   ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void FindNumbersWays(int m[][10], int x, int y)
{
	int res[10][10] = { 0 };
	int i = x;
	int j = y;

	res[i][j] = 1;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((i == 0 && j == 0) || (i == x && j == y))
			{
				continue;
			}
			else if (m[i][j] == 0)
			{
				res[i][j] = 0;
			}
			else if (i == 0)
			{
				res[i][j] = res[i][j - 1];
			}
			else if (j == 0)
			{
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
		}
	}

	PrintMap(res);
}