#include <stdio.h>

int main()
{
	int n1, n2, n3, n4;
	int max;
	
	printf("Enter 4 numbers: ");
	scanf_s("%d %d %d %d", &n1, &n2, &n3, &n4);
	
	if (n1 > n2)
	{
		if (n1 > n3)
		{
			if (n1 > n4)
			{
				printf("Max numbers: %d", n1);
			}
			else
			{
				printf("Max numbers: %d", n4);
			}
		}
		else if(n3 > n4)
		{
			printf("Max numbers: %d", n3);
		}
		else
		{
			printf("Max numbers: %d", n4);
		}
	}
	else if (n2 > n3)
	{
		if (n2 > n4)
		{
			printf("Max numbers: %d", n2);
		}
		else
		{
			printf("Max numbers: %d", n4);
		}
	}
	else if (n3 > n4)
	{
		printf("Max numbers: %d", n3);
	}
	else
	{
		printf("Max numbers: %d", n4);
	}

	return 0;
}