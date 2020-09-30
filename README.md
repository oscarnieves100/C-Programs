# C-Programs
C Programs for Numerical Computing

These programs are made for educational purposes only as part of an upcoming textbook that the author is working on. 
You may use them for your own personal learning.

The files "matrixOps.c" and "matrixOps.h" form a library of linear algebra functions including:
- Matrix arithmetic
- Determinants
- Cofactor matrices
- Matrix inversion
- Solution to linear systems by inversion

To see how this library is implemented, consult "linear_solver.c". 

Additionally, you may look at "LSA_linear.c" or "LSA_quad.c" which apply this library for
Least-Squares Analysis (linear regression) using straight line and quadratic fits respectively.


*Note:
All the programs have been tested on GCC on OSX and Windows. The functions assume that
variable-length arrays (VLAs) are enabled in your compiler (e.g. using C99 or higher)
