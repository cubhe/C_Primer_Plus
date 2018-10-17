#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 5
void copy(double (* he)[M], double (* ren)[M]);
int main(){
	double he[N][M];
	double ren[N][M];
	for (size_t i = 0; i < N; i++){
		for (size_t j = 0; j < M; j++){
			scanf("%lf", &he[i][j]);
		}
	}
	copy(he, ren);//注意函数位置啊啊啊

	for (size_t i = 0; i < N; i++){
		for (size_t j = 0; j < M; j++){
			printf("%3.2lf\t", ren[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
void copy(double(*he)[M], double(*ren)[M])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			*(*(ren+i)+j) =*(*(he+i)+j);
		}
	}
}
/*#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 5
void copy(double (*h)[M], double (*r)[M]);
int main(){
	double he[N][M];
	double ren[N][M];
	for (size_t i = 0; i < N; i++){
		for (size_t j = 0; j < M; j++){
			scanf("%lf", &he[i][j]);
		}
	}
	copy(he, ren);
	for (size_t i = 0; i < N; i++){
		for (size_t j = 0; j < M; j++){
			printf("%3.2lf\t", ren[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
void copy(double (*h)[M], double(*r)[M])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			r[i][j] = h[i][j];
		}
	}
	}*/