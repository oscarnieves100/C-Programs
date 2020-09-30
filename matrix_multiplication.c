/*------------------------------------
Matrix Multiplication.

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <errno.h>

// print Matrix
void printMatrix(int rows, int cols,  double M[rows][cols], char *name);

// Matrix product C = A*B
void matrixProduct(int rowsA, int colsA, int rowsB, int colsB, int rowsC, int colsC, double A[rowsA][colsA], double B[rowsB][colsB], double C[rowsC][colsC]);

//--- Main Program ---//
int main() {
	const int mA = 2;
	const int nA = 3;
	const int mB = 3;
	const int nB = 2;
	const int mC = 2;
	const int nC = 2;
	
	char *name1 = "A";
	char *name2 = "B";
	char *name3 = "C";
	
	//Define matrices here
	double A[mA][nA] = { {-1, 0, 3}, {-1, 1, 5} };
	double B[mB][nB] = { {2, 3}, {-2, 1}, {3,  2} };
	double C[mC][nC];

	//Multiply matrices
	matrixProduct(mA, nA, mB, nB, mC, nC, A, B, C);
	printMatrix(mC, nC, C, name3);
	return 0;
}

//--- Functions ---//
void printMatrix(int rows, int cols,  double M[rows][cols], char *name) {
	printf("%s = \n", name);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.4f\t", M[ i ][ j ]);	
		}
		printf("\n");
	}
}

// Matrix product C = A*B
void matrixProduct(int rowsA, int colsA, int rowsB, int colsB, int rowsC, int colsC, double A[rowsA][colsA], double B[rowsB][colsB], double C[rowsC][colsC]) {
	// check multiplication is possible
	if (colsA != rowsB) {
		fprintf(stderr, "Matrix dimensions do not match, multiplication not possible.");
		exit(-1);	
	}
	
	// proceed with operation
	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			for (int k = 0; k < colsA; k++) {
				C[ i ][ j ] += A[ i ][ k ]*B [ k ][ j ]; 
			}
		}
	}
}