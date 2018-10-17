#include<stdio.h>
#include<stdlib.h>
int main()
{
	int day;
	int old;
	scanf("%d", &old);
	day = old * 365;
	printf("您起码活了%d天。",day);
	system("pause");
	return 0;
}