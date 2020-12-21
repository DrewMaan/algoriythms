#include <stdio.h>

int main()
{
	float height, mass;

	printf("Enter a person height at meters: ");
	scanf_s("%f", &height);

	printf("Enter a person mass at kilograms: ");
	scanf_s("%f", &mass);

	float bmi = 0;
	bmi = mass / (height * height);
	printf("Body mass index: %.2f", bmi);
	return 0;
}