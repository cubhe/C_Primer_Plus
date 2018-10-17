#include<stdio.h>
#include<stdlib.h>
int sum(int a, int b);
int main(){
	int low, upp;
	do
	{
		printf("Enter lower and upper number:\n");
		while (scanf("%d %d", &low, &upp) != 2)
		{
			printf("Input again!\n");
			fflush(stdin);
		}
		if (low>=upp)
		{
			break;
		}
		printf("The sums of the squares from %d to %d is %d\n", low, upp, sum(low, upp));
		printf("The next set of limits:\n");
	} while (low < upp);
	printf("Done\n");
	system("pause");
	return 0;
}
int sum(int a, int b)
{
	int all=0;
	for (;a <=b;a++ )
	{
		all += (a*a);
	}
	return all;
}