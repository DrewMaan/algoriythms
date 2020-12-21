#include <stdio.h>

int main()
{
	float a, b, c;

	printf("Enter coefficients equation (a, b, c): ");
	scanf_s("%f %f %f", &a, &b, &c);

	printf("Equation: %d * x^2 + %d * x + c");
}