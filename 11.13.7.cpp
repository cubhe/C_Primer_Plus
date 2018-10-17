#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define WORDS "beast"
int main(){
	char * he = WORDS;
	char ren[40] = "Be the beast that you can be";
	char * zhi;
	puts(he);
	puts(ren);
	zhi = strcpy(ren + 7, he);
	puts(zhi);
	system("pause");
	return 0;
}