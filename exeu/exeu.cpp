#include "pch.h"
#include <iostream>
#define printf(fmt, ...)
#define scanf_s(cin, ...)

void func(int M, int N, int* x, int* y, int* L);
					
int main(void)
{
	int M, N, x, y, L;
	M = N = x = y = L = 0;

	printf("M : ");
	scanf_s("%d", &M);
	printf("N : ");
	scanf_s("%d", &N);
	printf("\n");

	func(M, N, &x, &y, &L);

	printf("M = %d\t", M);
	printf("x = %d\n", x);
	printf("N = %d\t", N);
	printf("y = %d\n", y);
	printf("GCD(M, N):L = %d\n\n", L);
	printf("式 : %d = %d * %d + %d * %d \n\n\n", L, M, x, N, y);

	return 0;

}

void func(int M, int N, int* x, int* y, int* L)
{
	int tmp, q;
	int u = 0;
	int v = 1;

	*x = 1;
	*y = 0;

	while (N > 0)
	{
		q = M / N;
		tmp = u;
		u = *x - q * u;
		*x = tmp;

		tmp = v;
		v = *y - q * v;
		*y = tmp;

		tmp = N;
		N = M - q * N;
		M = tmp;

	}
	*L = M;

}