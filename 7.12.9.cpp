//素数
#include<stdio.h>
#include<stdlib.h>
int main()
{
	long n;
	printf("请输入一个输：");
	scanf("%d", &n);
	printf("2\n");
	for (size_t i = 2; i <= n; i++)
	{
		for (size_t j = 2; j <= i; j++)
		{
			if (i%j == 0)
				break;
			if (j==i-1)
				printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}