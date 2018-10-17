#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, n;
	long p, sum = 1;
	printf("input n=");
	scanf("%d", &n);
	for (i = 1, p = 1; i <= n; i++)
	{
		p = p*i;
		sum = sum + p;
	}
	printf("1!+2!+бн+%d!=%d", n, sum);
	system("pause");
	return 0;
}