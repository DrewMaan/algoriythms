#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;

	printf("Enter coefficients equation (a, b, c) (a should be > 0): ");
	scanf_s("%f %f %f", &a, &b, &c);

	printf("Equation: %d * x^2 + %d * x + c\n");

	if (b == 0 && c == 0)
	{
		printf("Solution of equation: x = 0\n");
	}
	else if (b == 0)
	{
		float xSquare = (c * -1) / a;
		if (xSquare > 0)
		{
			float x1 = sqrt(xSquare);
			float x2 = -sqrt(xSquare);
			printf("Solution of equation: x1 = %f, x2 = %f\n", x1, x2);
		}
		else if(xSquare == 0)
		{
			printf("Solution of equation: x = 0\n");
		}
		else
		{
			printf("Equation has no solution\n");
		}
	}
	else if (c == 0)
	{
		float x = (b * -1) / a;
	}
	else
	{
		float D = b * b - 4 * a * c;
		if (D < 0)
		{
			printf("Equation has no solution\n");
		}
		else if (D == 0)
		{
			float x = (b * -1) / (2 * a);
			printf("Solution of equation: x = %f\n", x);
		}
		else
		{
			float x1 = (b * -1 + sqrt(D)) / (2 * a);
			float x2 = (b * -1 - sqrt(D)) / (2 * a);
			printf("Solution of equation: x1 = %f, x2 = %f\n", x1, x2);
		}
	}
}