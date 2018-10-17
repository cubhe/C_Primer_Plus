#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
char * strfind(char * he, char a);
int main(){
	char he[N],a;
	printf("Input a lettet:\n");
	scanf("%c", &a);
	getchar();
	printf("Input a sentens:\n");
	gets(he);
	printf("%c", *strfind(he, a));
    system("pause");
	return 0;
}
char * strfind(char * he, char a)
{
	for (size_t i = 0; i <strlen(he) ; i++)
	{
		if (he[i]==a)
		{
			return &he[i];
		}
	}
	return 0;
}