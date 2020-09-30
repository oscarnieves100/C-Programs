/*------------------------------------
Determinant of a matrix.

Created by: Oscar A. Nieves
--------------------------------------*/

#include <stdio.h>
#include <math.h>

void printMatrix(int rows, int cols,  double M[rows][cols], char *name);
double det(int n, double A[n][n]);

//--- Main Program ---//
int main() {
	// initialize matrices
	const int n1 = 3;
	double A1[n1][n1] = { {2, 1.2, -1}, {0, 1.2, 3.5}, {4, 5, -3} };
	double det_A1;
	char *name1 = "A1";
	
	const int n2 = 4;
	double A2[n2][n2] = { {-1, 1, 0, 2}, {0.2, 5.4, 3.2, -1}, {-2.2, 1, 2.3, 0.56}, {5.6, 4, 1, 0.9} };
	double det_A2;
	char *name2 = "A2";	
	
	// compute determinant and print values
	printf("\n");
	det_A1 = det(n1, A1);
	printMatrix(n1, n1, A1, name1);
	printf("\n");
	printf("det(%s) = %f\n", name1, det_A1);
	
	printf("\n");
	det_A2 = det(n2, A2);
	printMatrix(n2, n2, A2, name2);
	printf("\n");
	printf("det(%s) = %f\n", name2, det_A2);
	return 0; 
}

//--- Functions ---//
void printMatrix(int rows, int cols,  double M[rows][cols], char *name) {
	printf("%s = \n", name);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.2f\t", M[ i ][ j ]);	
		}
		printf("\n");
	}
}

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