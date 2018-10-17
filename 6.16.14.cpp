#include<stdio.h>
#include<stdlib.h>
int main(){
	char he[200];
	int i;
	for (i = 0;; i++)
	{
		scanf("%c", &he[i]);
		if (he[i] == '\n')
			break;
	}
	while (i>=0)
	{
		printf("%c ", he[i]);
		i--;
	}
	system("pause");
	return 0;
}