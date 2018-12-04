#include "opt.h"
#include <iostream>
using namespace std;

vec opt::steep(const mat &A, const vec &b, const num tol)
{
	static const int full_res_counter = 10;
	int m = A.dim(0), n = A.dim(1);
	vec x(n);
	vec r = b-A*x;
	num rem = r.norm2(), brem = b.norm2();
	vec s;
	num scl;
	int counter = 0;
	while (rem > tol*tol*brem) // while above relative tolerance
	{
		s = A*r; // Ar_i
		scl = rem/(r*s); // optimal solution to quadratic equation
		x += scl*r; // go in steepest direction
		if (counter++ % 10 == 0)
			r = b-A*x;
		else
			r -= scl*s; // r_{i+1}=b-A_{x_{i+1}}=b-A(x_i+scl*r_i)=b-Ax_i+scl*Ar_i=r_i-scl*Ar_i
		rem = r.norm2();
	}
	return x;
}
