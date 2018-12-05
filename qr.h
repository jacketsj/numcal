#include "mat.h"
#include "vec.h"

#ifndef qr_h
#define qr_h

namespace qr
{
	// Gram-Schmidt Orthogonalization
	// Given a matrix A,
	// Return an orthogonal matrix Q with the same columnspace as A
	// Optional parameter R for the transformation values
	// i.e. A=QR
	// Note that we use the 'economy' version,
	// so Q is unitary (m by n), and R is n by n
	mat gs(mat A, mat &Q);
	mat gs(mat A);

	// Householder transformations
	mat hh(mat A, mat &Q);
}

#endif
