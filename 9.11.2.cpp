#include<stdio.h>
#include<stdlib.h>
void chline(char ch, int i, int j);
int main()
{
	char ch = '!';
	int i, j;
	scanf("%d %d", &i, &j);
	chline(ch, i, j);
	system("pause");
	return 0;
}
void chline(char ch, int i, int j)
{
	for (size_t z = 1; z <= j; z++)
	{
		if (z<i)
		{
			printf("\n");
		}
		else
		{
			printf("%c\n", ch);
		}
	}
}