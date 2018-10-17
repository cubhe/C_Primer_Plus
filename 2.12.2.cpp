#include<stdio.h>
#include<stdlib.h>
int main()
{
	char name[10];
	printf("Input you name:");
	scanf("%s", &name);
	printf("You name is:%s  %d", &name, &name);
	system("pause");
	return 0;
}