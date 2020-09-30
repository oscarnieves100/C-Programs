/*------------------------------------
Least Squares Analysis for
a quadratic fit using the custom
library ``matrixOps". Requires
matrixOps.h and matrixOps.c
files.

Created by: Oscar A. Nieves
--------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "matrixOps.c"

void linspace(int n, double a, double b, double x[n]);
void func1D(int n, double x[n], double y[n]);
void LSA2(int n, double x[n], double S[n], double b[2][1]);

//--- Main Program ---//
int main () {
	const int k = 10;
	const double xmin = 0;
	const double xmax = 3;
	double xv[k];
	double data[k];
	double bsol[2][1];
	
	// create random data
	linspace(k, xmin, xmax, xv);
	func1D(k, xv, data);
	
	// do LSA
	LSA2(k, xv, data, bsol);
}

//--- Functions ---//
void linspace(int n, double a, double b, double x[n]) {
	double N;
	N = (double)n;
	double dx = (b - a)/(N-1); //step-size
	for (int i = 0; i < n; i++) {
		x[ i ] = a + dx*i;
	}
}

void func1D(int n, double x[n], double y[n]) {
	// initialize random numbers
	time_t t;
	srand((unsigned) time(&t));
	
	for (int i = 0; i < n; i++) {
		double R = (double)(-2 + rand() % 4);
		y[ i ] = 3*pow(x[ i ], 2) - 2*x[ i ] + R/10;	
	}
}

void LSA2(int n, double x[n], double S[n], double b[2][1]) {
	double A[3][3];
	double B[3][1];
	double mean_S;
	
	// prepare matrices
	A[0][0] = (double)n;
	for (int i = 0; i < n; i++) {
		A[0][1] += x[i];
		A[0][2] += pow(x[i], 2);
		A[1][0] += x[i];
		A[1][1] += pow(x[i], 2);
		A[1][2] += pow(x[i], 3);
		A[2][0] += pow(x[i], 2);
		A[2][1] += pow(x[i], 3);
		A[2][2] += pow(x[i], 4);
		B[0][0] += S[i];
		B[1][0] += x[i]*S[i];
		B[2][0] += pow(x[i], 2)*S[i];
		mean_S += 1/( (double)n ) * S[i] ; 
	}
	
	// invert matrix
	LSolve(3, A, B, b);
	printf("\n");
	
	// calculate R^2
	double yfit[n];
	double RV[n], SSres, SStot;
	for (int i = 0; i < n; i++) {
		yfit[ i ] =  b[0][0] + b[1][0] * x[ i ] + b[2][0] * pow(x[i], 2);
		SStot += pow(S[ i ] - mean_S , 2);
		SSres += pow(S[ i ] - yfit[ i ] , 2);
	}
	double Rsq = 1 - SSres/SStot;
	printf("R^2 = %.4f\n", Rsq);
}