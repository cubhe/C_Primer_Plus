#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
void revers(char * one);
int main(){
	char one[MAX];
	gets(one);
	revers(one);
	puts(one);
	system("pause");
	return 0;
}
void revers(char * one){
	char temp;
	int j = strlen(one);
	for (size_t i = 0; i < j/2; i++)
	{
		temp = one[i];
		one[i] = one[j - i-1];
		one[j - i-1] = temp;
	}
}