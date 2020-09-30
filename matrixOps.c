/*------------------------------------
Function definitions for the
``matrixOps.h'' library for linear
algebra operations, including
matrix arithmetic, determinants,
inverses and a linear solver.

Created by: Oscar A. Nieves
--------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <errno.h>
#include "matrixOps.h"

//--- MATRIX ARITHMETIC ---//
// print matrix
void printMatrix(int rows, int cols,  double M[rows][cols], char *name) {
	printf("%s = \n", name);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.4f\t", M[ i ][ j ]);	
		}
		printf("\n");
	}
}

// Adding/subtracting matrices m1 + m2 = outM OR m1 - m2 = outM
void addMatrix(int rows, int cols, double m1[rows][cols], double m2[rows][cols], double outM[rows][cols], char sign) {
	switch (sign) {
		case '+' : //addition
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					outM[ i ][ j ] = m1[ i ][ j ] + m2[ i ][ j ];
				}
			}
			break;
		case '-' : //subtraction
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					outM[ i ][ j ] = m1[ i ][ j ] - m2[ i ][ j ];
				}
			}
			break;
	}
}

// Multiplying matrix A*B = C
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

// Transpose of a matrix
void transpose(int m, int n, double M[m][n], double M_T[n][m]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {	
			M_T[ j ][ i ] = M[ i ][ j ]; //swap element locations
		}
	}
}

// Trace of a matrix
double trace(int rows, int cols, double M[rows][cols]) {
	double output1 = 0;
	for (int k = 0; k < rows; k++) {
		output1 += M[ k ][ k ];
	}
	return output1;
}


//--- DETERMINANTS AND INVERSES ---//
// Determinant
double det(int n, double A[n][n]) {
	double detA = 0;
	
	// check size of matrix
	if (n > 2) {
		// break matrix into smaller matrix
		for (int k = 0; k < n; k++) {
			double A_smaller[n-1][n-1];			
			
			// assign smaller matrix values
			for (int i = 0; i < n-1; i++) {
				int loop2 = 1;
				for (int j = 0; j < n-1; j++) {
					if (j < k) {
						A_smaller[ i ][ j ] = A[ i+1 ][ j ];					
					} else {
						A_smaller[ i ][ j ] = A[ i+1 ][ k+loop2 ];
						loop2 += 1;							
					}
				}  
			}
			detA += pow(-1,k)*A[0][k]*det(n-1, A_smaller);
		}	
	} else if (n == 2) {
		// Calculate 2x2 determinant
		detA = A[0][0]*A[1][1] - A[0][1]*A[1][0];
	} else {
		detA = A[0][0];	
	}
	return detA;
}

// Cofactor matrix
void cofactor(int n, double A[n][n], double C[n][n]) {	
	//C is the cofactor matrix of A
	 if (n == 2) {
		C[0][0] = A[1][1];
		C[0][1] = -A[1][0];
		C[1][0] = -A[0][1];
		C[1][1] = A[0][0];
	} else {
		// rows
		for (int x = 0; x < n; x++) {
			// columns
			for (int y = 0; y < n; y++){
				double M[n-1][n-1]; // minor matrix
				for (int i = 0; i < n-1; i++) {
					for (int j = 0; j < n-1; j++) {
						if (j < y) {
							if (i < x) {
								M[ i ][ j ] = A[ i ][ j ];
							} else {
								M[ i ][ j ] = A[ i+1 ][ j ];
							}
						} else {
							if (i <  x) {
								M[ i ][ j ] = A[ i ][ j+1 ];
							} else {
								M[ i ][ j ] = A[ i+1 ][  j+1 ];	
							}
						} 
					}
				}
				C[ x ][ y ] = pow(-1,x+y) * det(n-1, M);
			}
		}
	}
}

// Inverse matrix
void inv(int n, double A[n][n], double A_inv[n][n]) {
	double C[n][n];
	double C_T[n][n];
	double det_A;
	
	// calculate determinant of A
	det_A = det(n, A);
	
	// calculate cofactor matrix C
	cofactor(n, A, C);
	
	// take transpose of cofactor (adjoint matrix)
	transpose(n, n, C, C_T);
	
	// assign values to inverse matrix A_inv
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A_inv[ i ][ j ] = 1/det_A * C_T[ i ][ j ];
		}
	}
}


//--- LINEAR SOLVER ---//
// Solve linear system A*x = b for x
void LSolve(int n, double A[n][n], double b[n][1], double x[n][1]) {
	// Linear algebraic system solver A*x = b
	double A_inv[n][n];
	
	// calculate inverse of A
	inv(n, A, A_inv);
	
	// calculate x = A^{-1}*b
	matrixProduct(n, n, n, 1, n, 1, A_inv, b, x);
	
	// print values of x
	char *nameX = "x";
	printMatrix(n, 1, x, nameX);
}