#include<stdio.h>
#include<stdlib.h>
long SUM(int * start, int * end);
#define size 10
int main(){
	int member[size] = { 20, 3, 4, 5, 6, 77, 8, 5, 9, 65 };
	long sum;
	sum = SUM(member, member + size);
	printf("the sum of member is %ld", sum);
	system("pause");
	return 0;
}
long SUM(int * start, int * end){
	long sum = 0;
	while (start < end)
	{
		sum += *start++;
	}
	return sum;
}