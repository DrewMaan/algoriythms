/*
* 
*	����������� ����������� ����������� ����� �����, ���������� �� ������. � ����������� ��� �������, ������ ������� �������� �����:
*
*		������� 1
*		������ �� 2
*
*	������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� ����� � 2 ����. ������� ���������� ��������, ������� ����� 3 ����������� � ����� 20?
*		�) � �������������� �������;
*		�) � �������������� ��������.
*
*
*	����������� ������
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