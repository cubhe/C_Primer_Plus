#include<stdio.h>
#include<stdlib.h>
#define N 10
double cha(double num[]);
int main(){
	double num[N] = { 12, 123, 1412, 1432, 56, 4654, 3643, 3, 55, 6};
	printf("最大值与最小值的差为%lf", cha(num));
	system("pause");
	return 0;
}
double cha(double num[])
{
	double max = num[0],min = num[0];
	for (size_t i = 0; i < N; i++)
	{
		if (max<num[i])
			max = num[i];
		if (min>num[i])
			min = num[i];
	}
	return max - min;
}
