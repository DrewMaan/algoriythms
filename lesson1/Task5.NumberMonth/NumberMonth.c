#include <stdio.h>

int main()
{
	int month;

	printf("Enter month from 1 to 12: ");
	scanf_s("%d", &month);

	if (month >= 3 && month <= 5)
	{
		printf("Season: spring");
	}
	else if (month >= 6 && month <= 8)
	{
		printf("Season: summer");
	}
	else if (month >= 9 && month <= 11)
	{
		printf("Season: autumn");
	}
	else
	{
		printf("Season: winter");
	}
}