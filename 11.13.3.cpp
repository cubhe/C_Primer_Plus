#include<stdio.h>
#include<stdlib.h>
#define N 100
int get_s(char * he);
int main(){
	char he[N]; 
	int i=get_s(he);
	for (size_t  j= 0; j < i; j++)
	{
		printf("%c\n", he[j]);
	}
	printf("Done");
    system("pause");
	return 0;
}
int get_s(char * he){
	int i = 0;
	while ((he[i]=getchar())!=' ')
		i++;
	return i;
}