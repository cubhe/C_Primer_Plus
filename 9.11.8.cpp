#include <stdio.h>
#include<stdlib.h>
double power(double a, int b);
int main()
{
	double a;
	int b;//��������һ��Ҫ����
	scanf("%lf %d", &a, &b);
	printf("����ǣ�%lf", power(a, b));
	system("pause");
	return 0;
}
double power(double a, int b)
{
	if (b>1)
		return a*power(a, b - 1);
	else
		return a;
}
