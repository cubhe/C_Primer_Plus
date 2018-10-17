#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int letter[26];
	int n=97;
	for (size_t i = 0; i < 26; i++,n++)
	{
		letter[i] = n;
	}
	char a;
	scanf("%c", &a);
	for (size_t x = 0; x <= (a - 'a'); x++)
	{
		for (size_t i = 0; i <( (a - 'a')-x); i++)
		{
			printf(" ");
		}
		for (size_t y = 0; y <= x; y++)
		{
			printf("%c", letter[y]);
		}
		for (size_t z = x; z > 0; z--)
		{
			printf("%c", letter[z-1]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}