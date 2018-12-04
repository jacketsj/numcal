#include "mat.h"
#include "vec.h"

#ifndef qr_h
#define qr_h

namespace opt
{
	// steepest descent algorithm
	// solves Ax=b using steepest gradient descent
	vec steep(const mat &A, const vec &b, const num tol);
}

#endif
