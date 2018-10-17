#include<stdio.h>
#include<stdlib.h>
void print(char a, int n);
int main(){
	char a,b;
	a = b = getchar();
	int n = a - 'A';
	for (size_t i = 0; i <= n; i++)
	{
		print(a, i);
		printf("\n");
	}
	system("pause");
	return 0;
}
void print(char a, int n)
{
	for (size_t i = 0; i <= n; i++)
	{
		putchar(a);
		a--;
	}
}