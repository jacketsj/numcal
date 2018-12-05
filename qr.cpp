#include <cassert>
#include "qr.h"

mat qr::gs(mat A, mat &R)
{
	int m = A.dim(0), n = A.dim(1);

	A = A.t(); // make the columns of A directly accessible

	mat Q = mat::zero(n,m);
	R = mat::zero(n,n);

	// For each column in A
	for (int c = 0; c < n; ++c)
	{
		Q[c] = A[c];
		// Remove the components in the non-orthogonal directions
		for (int c_below = 0; c_below < c; ++c_below)
		{
			R[c_below][c] = (Q[c]*Q[c_below]);
			Q[c] -= R[c_below][c]*Q[c_below];
		}
		R[c][c] = Q[c].norm();
		Q[c] /= R[c][c];
	}

	Q = Q.t();

	return Q;
}

mat qr::gs(mat A)
{
	mat R;
	return gs(A,R);
}
