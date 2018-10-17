#include<stdio.h>
#include<stdlib.h>
void copy_arr(double sourse[], double target1[],int n);
void copy_prr(double*sourse, double*target1, int n);
void print(double target[],int n);
int main(){
	double sourse[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	copy_arr(sourse, target1, 5);
	copy_prr(sourse, target2, 5);
	print(target1, 5);
	print(target2, 5);
	system("pause");
	return 0;
}
void copy_arr(double sourse[], double target1[], int n)
{
	for (size_t i = 0; i < n; i++)
		target1[i] = sourse[i];
}
void copy_prr(double*sourse, double*target1, int n)
{
	for (size_t i = 0; i < n; i++)
		*(target1+i)= *(sourse+i);
}
void print(double target[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%lf\n", target[i]);
	}
}


