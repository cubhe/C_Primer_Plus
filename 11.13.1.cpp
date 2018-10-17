#include<stdio.h>
#include<stdlib.h>
#define N 10
void get_s(char * he);
int main(){
	char he[N]; 
	get_s(he);
	printf("Done");
    system("pause");
	return 0;
}
void get_s(char * he){
	int i = 0;
	while (scanf("%c",&he[i])==1&&i<N-1)
		i++;
}