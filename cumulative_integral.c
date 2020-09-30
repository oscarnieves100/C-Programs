/*-----------------------------------------------
Simple program for computing the cumulative
integral of a function f(x) using the trapezoidal rule. 
The default example is
the integral of x^2 on the domain x = [1, 3].

Created by: Oscar A. Nieves
-----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void linspace(int N, double xlow, double xhigh, double x[N]);
void yfunc(int N, double x[N], double y[N]);
void cumulative_trapz(int N, double xlow, double xhigh, double f[N], double F[N]);
double perc_error(int N, double exact_val, double numeric_val);

//--- Main Program ---//
int main() {
	// input parameters
	const int N = 20; //# of points in domain
	const double a = 1; //lower bound
	const double b = 3; //upper bound
	double I_exact; //exact integral
	double I_numeric; //numeric estimate
	double xv[N], fv[N], FV[N]; //arrays
	double step; //step-size
	
	//generate array x	
	linspace(N, a, b, xv);
	
	//define function y = f(x)	
	yfunc(N, xv, fv);
	
	//calculate integral
	cumulative_trapz(N, a, b, fv, FV);
	
	//check error at each point
	int trapezoids = N - 1;
	double dx = (b - a) / ( (double)trapezoids );
	for (int n = 1; n < N; n++) {
		// exact integral of x^2
		I_exact = (pow(a + n*dx, 3) - pow(a, 3)) / 3;
		I_numeric = FV[n];
		double error_p = perc_error(N, I_exact, I_numeric);
		printf("I_numeric = %.4f\n", I_numeric);
		printf("I_exact = %.4f\n", I_numeric);
		printf("percentage error = %.4f\n", error_p);
		printf("\n");
	}
	
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

void cumulative_trapz(int N, double xlow, double xhigh, double f[N], double F[N]) {
	// F[n] is the anti-derivative of f[n]	
	int trapezoids = N - 1;
	double dx = (xhigh - xlow) / ( (double)trapezoids );
	
	F[0] = 0; //default value
	for (int n = 1; n < N; n++) {;
		F[n] = F[n-1] + 0.5 * dx * (f[n-1] + f[n]);
	}
 }

double perc_error(int N, double exact_val, double numeric_val) {
	double error_percentage;
	error_percentage = 100*fabs( (exact_val - numeric_val)/exact_val );	
	return error_percentage;
}