#include<stdio.h>
#include<stdlib.h>
#define N 3
void readnum(int(*mat)[5] );
void Add(int(*mat)[5] ,int add[3]);
void addall(int(*mat)[5], float * all);
void findmax(int(*mat)[5], int * max);
void pri(int add[3], float all, int max);
int main(){
	int mat[3][5];
	int add[3], max = 0;
	float all;
	printf("Input a 3*5 matrix:\n");
	readnum(mat);
	Add(mat, add);
	addall(mat, &all);
	findmax(mat, &max);
	pri(add, all, max);
	system("pause");
	return 0;
}
void readnum(int(*mat)[5]){
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
}
void Add(int(*mat)[5], int add[3])
{
	for (size_t i = 0; i < 3; i++)
	{
		add[i] = 0;
		for (size_t j = 0; j < 5; j++)
		{
			add[i] += mat[i][j];
		}
		add[i] /= 5;
	}
}
void addall(int(*mat)[5], float * all)
{
	*all = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			*all+= mat[i][j];
		}
	}
	*all /= 5.;
}
void findmax(int(*mat)[5], int * max)
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (*max < mat[i][j])
				*max = mat[i][j];
		}
	}
}
void pri(int add[3], float all, int max){
	printf("三组数的平均数分别为");
	for (size_t i = 0; i < 3; i++)
	{
		printf("%d  ", add[i]);
	}
	printf("\n");
	printf("平均数为%.2f\n", all);
	printf("最大值为%d\n", max);
}

