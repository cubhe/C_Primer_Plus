#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[20];
	scanf("%s", a);
	for (size_t i = strlen(a); i > 0; i--)
	{
		printf("%c\n", a[i-1]);
	}
	system("pause");
	return 0;
}