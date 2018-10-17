#include<stdio.h>
#include<stdlib.h>
void larger_of(double a, double b);
int main()
{
	double a, b;
	while (scanf("%lf %lf",&a,&b)==2)
	{
		larger_of(a, b);
	}
	system("pause");
	return 0;
}
void larger_of(double a,  double b)
{
	a < b ? a = b : b = a;
	printf("%.3lf %.3lf", a, b);
}

