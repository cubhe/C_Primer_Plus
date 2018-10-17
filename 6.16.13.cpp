#include<stdio.h>
#include<stdlib.h>
double Two(double *one, double *two,int i);
int main(){
	double one[8], two[8];
	for (int i = 0; i < 8; i++)
		scanf("%lf", &one[i]);
	printf("%lf\n",two[0] = one[0]);
	for (size_t j = 1; j < 8; j++)
	{ 
		two[j] = two[j - 1] + one[j];
		printf("%lf\n", two[j]);
	}
	system("pause");
	return 0;
}
