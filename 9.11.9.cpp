#include <stdio.h>
#include<stdlib.h>
void to_binary(long n,int m);
int main()
{
	long n;
	int m;
	printf("������Ҫת�������ͽ���:");
	while (scanf("%d %d", &n, &m)==2)
	{
		to_binary(n, m);
		putchar('\n');
		printf("������Ҫת�������ͽ���:");
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
