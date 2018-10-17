#include<stdio.h>
#include<stdlib.h>
int main(){
	char ohh[100];
	for (size_t i = 0; (ohh[i] = getchar()) != '\n'; i++)
	{
		putchar(ohh[i]);
		putchar('\n');
	}
	system("pause");
	return 0;
}