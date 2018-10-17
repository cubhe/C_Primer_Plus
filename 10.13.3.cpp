#include<stdio.h>
#include<stdlib.h>
#define N 10
int select(int*num);
int main(){
	int num[N] = { 1, 4, 5, 66, 85, 32, 255, 67, 342, 14, };
	printf("the bigest number in num is %d", select(num));
	system("pause");
	return 0;
}
int select(int * num)
{
	int temp=0;
	for (size_t i = 0; i < N; i++)
	{
		if (temp<*num)
		{
			temp = *num;
		}
		num++;
	}
	return temp;
}