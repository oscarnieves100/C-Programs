/*------------------------------------
Inverse of a matrix.

Created by: Oscar A. Nieves
--------------------------------------*/

#include <stdio.h>
#include <math.h>

// Declare functions
void printMatrix(int rows, int cols,  double M[rows][cols], char *name);
double det(int n, double A[n][n]);
void transpose(int m, int n, double M[m][n], double M_T[n][m]);
void cofactor(int n, double A[n][n], double C[n][n]);
void inv(int n, double A[n][n], double A_inv[n][n]);

//--- Main Program ---//
int main() {
	// initialize matrix
	const int n1 = 3;
	const int n2 = 4;
	double A1[n1][n1] = { {2, 1.2, -1}, {0, 1.2, 3.5}, {4, 5, -3} };
	double A2[n2][n2] = { {1, 3, -1, 4}, {-1, -2.4, 5.5, 6.1}, {-0.12, 2.13, -5.6, -4.3}, {0.5, 0.67, -1.12, 9.54} };
	double A1_inv[n1][n1];
	double A2_inv[n2][n2];
	char *name1 = "A1";
	char *name2 = "A2";
	char *name1inv = "A1^{-1}";
	char *name2inv = "A2^{-1}";
	
	// compute inverse using cofactor method
	inv(n1, A1, A1_inv);
	inv(n2, A2, A2_inv);
	
	// print values
	printf("\n");
	printMatrix(n1, n1, A1, name1);
	printf("\n");
	printMatrix(n1, n1, A1_inv, name1inv);
	printf("\n");
	printMatrix(n2, n2, A2, name2);
	printf("\n");
	printMatrix(n2, n2, A2_inv, name2inv);
	printf("\n");
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

//--- Transpose
void transpose(int m, int n, double M[m][n], double M_T[n][m]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {	
			M_T[ j ][ i ] = M[ i ][ j ]; //swap element locations
		}
	}
}

//--- Determinant
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

//--- Cofactor matrix
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

//--- Inverse
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