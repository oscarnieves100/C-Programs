/*------------------------------------
Function declarations for the
library for linear algebra 
operations. Function definitions 
are given in ``matrixOps.c''.

Created by: Oscar A. Nieves
--------------------------------------*/

//--- MATRIX ARITHMETIC ---//
// print matrix
void printMatrix(int rows, int cols,  double M[rows][cols], char *name);

// Adding/subtracting matrices m1 + m2 = outM OR m1 - m2 = outM
void addMatrix(int rows, int cols, double m1[rows][cols], double m2[rows][cols], double outM[rows][cols], char sign);

// Multiplying matrix A*B = C
void matrixProduct(int rowsA, int colsA, int rowsB, int colsB, int rowsC, int colsC, double A[rowsA][colsA], double B[rowsB][colsB], double C[rowsC][colsC]);

// Transpose of a matrix
void transpose(int m, int n, double M[m][n], double M_T[n][m]);

// Trace of a matrix
double trace(int rows, int cols, double M[rows][cols]);


//--- DETERMINANTS AND INVERSES ---//
// Determinant
double det(int n, double A[n][n]);

// Cofactor matrix
void cofactor(int n, double A[n][n], double C[n][n]);

// Inverse matrix
void inv(int n, double A[n][n], double A_inv[n][n]);


//--- LINEAR SOLVER ---//
// Solve linear system A*x = b for x
void LSolve(int n, double A[n][n], double b[n][1], double x[n][1]);