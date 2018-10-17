#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, n;
	long p;
	scanf("%d", &n);
	for ( i = 1,p=1; i <=n; i++)
	{
		p = p*i;
		printf("%d=%d\n", i, p);
	}
	system("pause");
	return 0;
}