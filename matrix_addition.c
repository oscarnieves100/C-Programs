/*------------------------------------
Addition and subtraction of matrices

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

//-- Print Matrix
void printMatrix(int rows, int cols,  double M[rows][cols], char *name);

//-- Add and subtract matrices
void addMatrix(int rows, int cols, double m1[rows][cols], double m2[rows][cols], double outM[rows][cols], char sign);

//--- Main Program ---//
int main() {
	const int row = 2;
	const int col = 3;

	char *name1 = "M1";
	char *name2 = "M2";
	char *name3 = "M3";
	
	//Define matrices here
	double matrix1[row][col] = { {-1, 0, 3}, {-1, 1, 5} };
	double matrix2[row][col] = { {1, 3, 4}, {-7, 1, 6} };
	double matrix3[row][col];
	
	//Addition and subtraction here (matrix3 is the output)
	addMatrix(row, col, matrix1, matrix2, matrix3, '+');
	printf("%s + %s = ", name1, name2);
	printMatrix(row, col, matrix3, name3 );
	printf("\n");
	
	addMatrix(row, col, matrix1, matrix2, matrix3, '-');
	printf("%s - %s = ", name1, name2);
	printMatrix(row, col, matrix3, name3 );
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