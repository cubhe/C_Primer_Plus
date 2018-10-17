#include<stdio.h>
#include<stdlib.h>
int main(){
	int days;
	printf("Input days:");
	scanf("%d", &days);
	printf("%d days are %d weeks %d days", days, days / 7, days % 7);
	system("pause");
	return 0;
}