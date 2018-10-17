#include<stdio.h>
#include<stdlib.h>
void dou(int (*nums)[5], int n, int m);
void pri(int(*nums)[5], int n, int m);
//我的天 这个指针好怪啊int(*)[],int(*)[5]到底有毛区别？？
int main(){
	int nums[3][5]  = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	dou(nums,3,5);
	pri(nums, 3, 5);
	system("pause");
	return 0;
}
void dou(int (*nums)[5], int n, int m){
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			nums[i][j] *= 2;
		}
	}
}
void pri(int(*nums)[5], int n, int m){
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			printf("%d\n",nums[i][j]);
		}
	}
}
