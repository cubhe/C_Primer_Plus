#include<stdio.h>
#include<stdlib.h>
#define N 10
double Num(double*num);
int main(){
	double num[10] = { 2, 3, 4, 5, 6, 7, 1122, 34565, 3214, 5343 };
	printf("最大值的地址是%p", Num(num));
	system("pause");
	return 0;
}
double Num(double * num)
{
	int o;
	float temp = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (temp<*num)
		{
			temp = *num;
			o = i;
		}
		num++;
	}
	return (num + o);
}