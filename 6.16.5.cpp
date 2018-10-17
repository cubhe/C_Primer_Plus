#include<stdio.h>
#include<stdlib.h>
int main()
{
	float min, max;
	printf("输入上限与下限：");
	scanf("%f %f", &min, &max);
	for (;min!=max;min++)
	{
		printf("%7.2f  %7.2f  %7.2f\n", min, min*min, min*min*min);
	}
	system("pause");
	return 0;
}