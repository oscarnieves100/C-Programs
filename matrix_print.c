/*------------------------------------
This program prints out a matrix.

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

//-- Print Matrix
void printMatrix(int rows, int cols,  double M[rows][cols], char *name);

//--- Main Program ---//
int main() {
	const int row = 3;
	const int col = 3;
	char *name1 = "M1";
	double matrix1[row][col] = { {-1, 0, 3}, {0, 1, 0}, {2, 3, -1} };
	printMatrix(row, col, matrix1, name1);
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