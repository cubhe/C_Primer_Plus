#include <stdio.h>
#include<stdlib.h>
void to_binary(long n,int m);
int main()
{
	long n;
	int m;
	printf("输入需要转换的数和进制:");
	while (scanf("%d %d", &n, &m)==2)
	{
		to_binary(n, m);
		putchar('\n');
		printf("输入需要转换的数和进制:");
	}
	system("pause");
	return 0;
}
void to_binary(long n,int m)
{
	int r;
	r = n%m;
	if (n >= m)
	{
		to_binary(n / m,m);
	}
	putchar('0'+r);
	return;
}
