/*------------------------------------
Solving a linear system of
equations using the custom
library ``matrixOps". Requires
matrixOps.h and matrixOps.c
files.

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrixOps.c"

int main() {
	const int n = 3;
	double A[n][n] = { {1,0,2}, {3,2,4}, {-1,5,6} };
	double b[n][1] = { {2}, {-3}, {4} };
	double x[n][1];
	double A_inv[n][n];
	char *nameA = "A^{-1}";
	
	inv(n, A, A_inv);
	printMatrix(n, n, A_inv, nameA);
	printf("\n");
	LSolve(n, A, b, x);
	printf("\n");
	return 0;
}