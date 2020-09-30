/*-----------------------------------------------
Simple program for computing an integral 
using the trapezoidal rule. 
The default example is
the integral of x^2 on the domain x = [1, 3].

Created by: Oscar A. Nieves
-----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void linspace(int N, double xlow, double xhigh, double x[N]);
void yfunc(int N, double x[N], double y[N]);
double trapz(int N, double xlow, double xhigh, double y[N]);
double perc_error(int N, double exact_val, double numeric_val);

//--- Main Program ---//
int main() {
	// input parameters
	const int N = 40; //# of points in domain
	const double a = 1; //lower bound
	const double b = 3; //upper bound
	double I_exact = 8.6667; //exact integral
	double I_numeric; //numeric estimate
	double xv[N], yv[N]; //arrays
	double step; //step-size
	
	//generate array x	
	linspace(N, a, b, xv);
	
	//define function y = f(x)	
	yfunc(N, xv, yv);
	
	//calculate integral
	I_numeric = trapz(N, a, b, yv);
	
	//check error
	double error_p = perc_error(N, I_exact, I_numeric);
	printf("I_exact = %.4f\n", I_exact);
	printf("I_numeric = %.4f\n", I_numeric);
	printf("percentage error = %.4f\n", error_p);	
	
	return 0;
}

//--- Functions ---//
void linspace(int N, double xlow, double xhigh, double x[N]) {
	int spacings = N - 1;
	double step_size = (xhigh - xlow) / ( (double)spacings );
	for (int i = 0; i < N; i++) {
		x[ i ] = xlow + i * step_size;
	}
}

void yfunc(int N, double x[N], double y[N]) {
	for (int i = 0; i < N; i++) {
		y[ i ] = pow(x[ i ], 2); //function y = f(x)
	}
}

double trapz(int N, double xlow, double xhigh, double y[N]) {
	int trapezoids = N - 1;
	double step = 0.5 * (xhigh - xlow) / ( (double)trapezoids );	
	
	//add end points
	double integral_val = step * (y[0] + y[N-1]);
	
	//add values in between
	for (int n = 1; n < N-1; n++) {
		integral_val += 2 * step * y[n];
	}
	
	return integral_val;
 }

double perc_error(int N, double exact_val, double numeric_val) {
	double error_percentage;
	error_percentage = 100*fabs( (exact_val - numeric_val)/exact_val );	
	return error_percentage;
}