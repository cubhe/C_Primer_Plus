#include<stdio.h>
#include<stdlib.h>
int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("��гֵ��%.3lf", 2/ (1 / a + 1 / b));
	system("pause");
	return 0;
}
