#include <stdio.h>

int main()
{
	int a, b;
	a = 341;
	b = 7843;
	printf("Variables a = %d and b = %d\n", a, b);

	//a
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("Swap variables 1: a = %d and b = %d\n", a, b);

	a = 341;
	b = 7843;
	//b
	a ^= b;
	b ^= a;
	a ^= b;
	printf("Swap variables 2: a = %d and b = %d\n", a, b);

	return 0;
}