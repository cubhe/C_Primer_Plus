#include<stdio.h>
#include<stdlib.h>
int main(){
	int num[8];
	for (size_t i = 0; i < 8; i++)
		scanf("%d", &num[i]);
	for (size_t n = 8; n > 0; n--)
		printf("%d ", num[n-1]);
	system("pause");
	return 0;
}