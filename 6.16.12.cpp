#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int num[8];
	int j = 0;
	for (size_t i = 0; i < 8; i++)
		num[i] = pow(2., i + 1.);
	do
	{
		printf("%d ", num[j]);
		j++;
	} while (j<8);
	system("pause");
	return 0;
}