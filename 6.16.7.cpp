#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	float a, b;
	do
	{
		if (scanf("%f,%f", &a, &b))
		{
			printf("两者差除以两者乘积为%f", (a - b) / (a*b));
		}
		else
		{
			printf("error");
			fflush(stdin);
		}
	} while (a==0&&b==0);
	system("pause");
	return 0;
}