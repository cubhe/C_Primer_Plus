#include<stdio.h>
#include<stdlib.h>
long Fibonacci(int n);
int main()
{
	int n;
	while (scanf("%d", &n)==1)
	{
		printf("%ld\n", Fibonacci(n));
	}
	system("pause");
	return 0;
}
long Fibonacci(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}