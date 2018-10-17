#include <stdio.h>
#include<stdlib.h>
double power(double a, int b);
int main()
{
	double a;
	int b;
	scanf("%lf %d", &a, &b);
	printf("½á¹ûÊÇ£º%.3lf", power(a, b));
	system("pause");
	return 0;
}
double power(double a, int b)
{
	double temp = a;
	for (size_t i = 1; i < b; i++)
	{
		a *= temp;
	}
	return a;
}