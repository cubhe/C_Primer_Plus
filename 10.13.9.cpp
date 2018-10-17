#include<stdio.h>
#include<stdlib.h>
#define N 8
void add(int(*a), int(*b), int(*c));
int main(){
	int a[N] = { 1, 9, 9, 8, 0, 5, 1, 1 };
	int b[N] = { 1, 9, 9, 8, 1, 1, 2, 1 };
	int c[N];
	add(a, b, c);
	for (size_t i = 0; i < N; i++){
		printf("%d ",c[i]);
	}
	system("pause"); 
	return 0;
}
void add(int(*a), int(*b), int(*c))
{
	for (size_t i = 0; i < N; i++)
	{
		*(c + i) = *(b + i) + *(a + i);
	}
}