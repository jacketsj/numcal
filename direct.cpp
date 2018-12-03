#include "direct.h"

vec direct::ge(mat A, vec b)
{
	int m = A.dim(0);
	// forward substitution
	// for each row
	for (int r = 0; r < m; ++r)
		// for each row below it
		for (int r_below = r+1; r_below < m; ++r_below)
		{
			// Subtract off the row so that A[r_below][r] becomes zero
			num scale = (A[r_below][r])/(A[r][r]);
			A[r_below] -= scale * A[r];
			// and also the constant vector
			b[r_below] -= scale * b[r];
		}
	// then call backward substitution
	vec ans = backsub(A,b);
	return ans;
}

vec direct::backsub(mat A, vec b)
{
	// assume A is upper triangular
	// rid of all diagonals
	int m = A.dim(0), n = A.dim(1);

	vec ret(n);

	// for each row
	for (int r = m-1; r >= 0; --r)
	{
		// we can do A[r]*ret because ret is prefixed by zeros by default
		ret[r] = (1/A[r][r]) * (b[r] - A[r]*ret);
	}
	return ret;
}
