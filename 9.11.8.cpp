#include <stdio.h>
#include<stdlib.h>
double power(double a, int b);
int main()
{
	double a;
	int b;//变量定义一定要清晰
	scanf("%lf %d", &a, &b);
	printf("结果是：%lf", power(a, b));
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
