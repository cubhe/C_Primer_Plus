#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
char  is_within(char * he, char a);
int main(){
	char he[N],a;
	printf("Input a lettet:\n");
	scanf("%c", &a);
	getchar();
	printf("Input a sentens:\n");
	gets(he);
	if (is_within(he, a))
		printf("在\n");
	else
		printf("不在\n");
    system("pause");
	return 0;
}
char  is_within(char * he, char a)
{
	for (size_t i = 0; i <strlen(he) ; i++){
		if (he[i]==a){
			return 1;
		}
	}
	return 0;
}