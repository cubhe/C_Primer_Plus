#include<stdio.h>
#include<stdlib.h>
#define N 100
void get_s(char * he);
int main(){
	char he[N]; 
	get_s(he);
	printf("%c\n", he[5]);
	printf("Done");
    system("pause");
	return 0;
}
void get_s(char * he){
	int i = 0;
	while ((he[i]=getchar())!='\n'&&he[i]!=' '&&he[i]!='\t')
		i++;
}