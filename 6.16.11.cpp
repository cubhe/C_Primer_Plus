#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float sum_a(int i);
float sum_b(int i);
int main(){
	int i;
	scanf("%d", &i);
	printf("first one is %f\nscend one is %f\n", sum_a(i), sum_b(i));
	system("pause");
	return 0;
}
float sum_a(int n)
{
	float sum=0;
	for (size_t i = 1; i < n+1; i++)
	{
		sum += (float)1. / i;
	}
	return sum;
}
float sum_b(int n)
{
	float sum = 0;
	for (size_t i = 1; i < n+1; i++)
	{
		sum += (float)1. / i*pow(-1.,i-1.);
	}
	return sum;
}