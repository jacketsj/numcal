#include <cassert>
#include "direct.h"

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

vec direct::gepp(mat A, vec b)
{
	int m = A.dim(0);
	// forward substitution
	// for each row
	for (int r = 0; r < m; ++r)
	{
		// find the row with the largest first non-zero value
		int largest_index = r;
		for (int r_poss = r+1; r_poss < m; ++r_poss)
			if (abs(A[r_poss][r]) > abs(A[r][r]))
				largest_index = r_poss;
		// make it the pivot
		swap(A[r],A[largest_index]);
		swap(b[r],b[largest_index]);

		//this decreases numerical error due to approximate zeroes
		
		// for each row below it
		for (int r_below = r+1; r_below < m; ++r_below)
		{
			// Subtract off the row so that A[r_below][r] becomes zero
			num scale = (A[r_below][r])/(A[r][r]);
			A[r_below] -= scale * A[r];
			// and also the constant vector
			b[r_below] -= scale * b[r];
		}
	}
	// then call backward substitution
	vec ans = backsub(A,b);
	return ans;
}

void direct::lu(mat A, mat &L, mat &U)
{
	int m = A.dim(0), n = A.dim(1);
	assert(m==n);
	int d = m;

	L = mat(d,d);
	U = mat(d,d);

	// forward substitution
	// for each row
	for (int r = 0; r < m; ++r)
	{
		//this decreases numerical error due to approximate zeroes

		L[r][r] = 1; // diaognals are 1
		
		// for each row below it
		for (int r_below = r+1; r_below < m; ++r_below)
		{
			// Compute cancellation factor
			num scale = (A[r_below][r])/(A[r][r]);
			L[r_below][r] = scale;
		}
	}

	U = A;
}

void direct::plu(mat A, mat &P, mat &L, mat &U)
{
	int m = A.dim(0), n = A.dim(1);
	assert(m==n);
	int d = m;

	P = mat(d,d);
	L = mat(d,d);
	U = mat(d,d);

	for (int i = 0; i < d; ++i)
		P[i][i] = 1;

	// forward substitution
	// for each row
	for (int r = 0; r < m; ++r)
	{
		// find the row with the largest first non-zero value
		int largest_index = r;
		for (int r_poss = r+1; r_poss < m; ++r_poss)
			if (abs(A[r_poss][r]) > abs(A[r][r]))
				largest_index = r_poss;
		// make it the pivot
		swap(P[r],P[largest_index]);
		swap(A[r],A[largest_index]);

		//this decreases numerical error due to approximate zeroes

		L[r][r] = 1; // diaognals are 1
		
		// for each row below it
		for (int r_below = r+1; r_below < m; ++r_below)
		{
			// Compute cancellation factor
			num scale = (A[r_below][r])/(A[r][r]);
			L[r_below][r] = scale;
			A[r_below] -= scale * A[r];
		}
	}

	U = A;
}
