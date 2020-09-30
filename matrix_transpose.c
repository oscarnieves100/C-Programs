/*------------------------------------
Matrix transpose

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// print Matrix
void printMatrix(int rows, int cols, double M[rows][cols], char *name);

// Matrix transpose
void transpose(int m, int n, double M[m][n], double M_T[n][m]);

//--- Main Program ---//
int main() {
	const int row = 2;
	const int col = 4;
	char *name1 = "A";
	char *name2 = "transpose(A)";
	
	// define matrices here
	double A[row][col] = { {-1, 2, 0, -1}, {0, -1, -5, 3} };
	double AT[col][row];

	// transpose
	transpose( row, col, A, AT );
	printMatrix( col, row, AT, name2 );
	printf("\n");
	return 0;
}

//--- Functions ---//
void printMatrix(int rows, int cols, double M[rows][cols], char *name) {
	printf("%s = \n", name);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.2f\t", M[ i ][ j ]);	
		}
		printf("\n");
	}
}

void transpose(int m, int n, double M[m][n], double M_T[n][m]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {	
			M_T[ j ][ i ] = M[ i ][ j ]; //swap element locations
		}
	}
}