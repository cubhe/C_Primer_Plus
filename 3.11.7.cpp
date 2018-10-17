#include<stdio.h>
#include<stdlib.h>
int main()
{
	float inch, high_1, high_2;
	inch = 2.54;
	printf("You high is:");
	scanf("%f", &high_1);
	high_2 = high_1 / inch;
	printf("Now,you high is:%f\n", high_2);
	system("pause");
	return 0;
}
