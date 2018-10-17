#include<stdio.h>
#include<stdlib.h>
void three(char ch, int a, int j);
int main()
{
	printf("Input a char and two int:");
	char ch;
	ch = getchar();
	int a, b;
	scanf("%d %d", &a,&b);
	three(ch, a, b);
	system("pause");
	return 0;
}
void three(char ch, int a, int b)
{
	for (size_t i = 0; i < b; i++)
	{
		for (size_t j = 0; j < a; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}