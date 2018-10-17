#include<stdio.h>
#include<stdlib.h>
int main()
{
	float a, b;
	a = b = 100;
	int year;
	for ( year = 0; a>=b; year++)
	{
		a = a + 10;
		b = b*(1.f + 0.005f);
	}
	printf("%d\n", year + 1);
	system("pause");
	return 0;
}