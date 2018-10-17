#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
void enen(char * one);
int main(){
	char one[MAX];
	gets(one);
	while (one[0] != '\0')
	{
		enen(one);
		puts(one);
		gets(one);
	} 
	printf("byebye!");
	system("pause");
	return 0;
}

void enen(char * one)
{
	for (size_t i = 0; i < strlen(one); i++)
	{
		while(one[i]==' ')
		{
			for (size_t j = i; j < strlen(one); j++)
			{
				one[j] = one[j + 1];
			}
		}
	}
}