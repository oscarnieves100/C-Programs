/*------------------------------------
Trace of a matrix

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int cols, double M[rows][cols], char *name);
double trace(int rows, int cols, double M[rows][cols]);

//--- Main Program ---//
int main() {
	const int m = 4;
	const int n = 4;
	char *name1 = "A";
	char *name2 = "tr(A)";
	
	// define matrices here
	double A[m][n] = { {-1, 2, 0, -1}, {0, -1, -5, 3}, {-1, 0, 2, 3}, {5, 6, 7, 8} };
	double traceA;

	// trace A
	printMatrix( m, n, A, name1 );
	printf("\n");
	traceA = trace( m, n, A );
	printf("tr(A) = %.2f\n", traceA);
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

double trace(int rows, int cols, double M[rows][cols]) {
	double output1 = 0;
	for (int k = 0; k < rows; k++) {
		output1 += M[ k ][ k ];
	}
	return output1;
}