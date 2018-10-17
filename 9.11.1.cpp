#include <stdio.h>
#include<stdlib.h>
double min(double x, double y);
int main()
{
	double x, y;
	printf("Input x y(q to quit):");
	while (scanf("%ld %ld", &x, &y) == 2)
	{
		printf("min=%ld", min(x, y));
		printf("Input x y:");
	}
	system("pause");
	return 0;
}
double min(double x, double y)
{
	if (x<=y)
	{
		return y;
	}
	else
	{
		return x;
	}
}