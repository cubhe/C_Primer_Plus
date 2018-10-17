#include<stdio.h>
#include<stdlib.h>
int main()
{
	float money = 100.;
	int year;
	for (year = 1;money>0; year++)
	{
		money = money* (1 + 0.008f) - 10;
	}
	printf("%d\n", year);
	system("pause");
	return 0;
}