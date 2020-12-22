#include <stdio.h>

int main()
{
	int age;
	printf("Eneter age (1 - 150): ");
	scanf_s("%d", &age);

	if (age % 10 == 1 && age % 100 != 11)
	{
		printf("%d год\n", age);
	}
	else if(age % 10 >= 2 && age % 10 <= 4)
	{
		if (age % 100 != 12 && age % 100 != 13 && age % 100 != 14)
		{
			printf("%d года\n", age);
		}
		else
		{
			printf("%d лет\n", age);
		}
	}
	else
	{
		printf("%d лет\n", age);
	}
}