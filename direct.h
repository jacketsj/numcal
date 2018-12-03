#include "mat.h"
#include "vec.h"

namespace direct
{
	// gives x from Ax=b directly, where A is upper triangular
	vec backsub(mat A, vec b);

	// gives x from Ax=b
	// using basic gaussian elimination then backprop
	// assume A is not rank deficient
	vec ge(mat A, vec b);

	// gives x from Ax=b
	// using gaussian elimination with partial pivoting then backprop
	// assume A is not rank deficient
	vec gepp(mat A, vec b);

	// compute LU decomposition of A
	// L is a lower triangular matrix
	// U is upper triangular
	// L and U in the parameters are return values
	// assumes we will never run into a zero-valued diagonal (otherwise use plu)
	void lu(mat A, mat &L, mat &U);

	// compute PLU decomposition of A
	// P is the permutation matrix
	// L is a lower triangular matrix
	// U is upper triangular
	// L and U in the parameters are return values
	void plu(mat A, mat &P, mat &L, mat &U);

	// compute the Cholesky decomposition of A
	// i.e. a matrix G such that GG^T=A
	// and G is lower triangular
	// We assume A is symmetric positive definite
	// i.e. that x^TAx>0 for all x
	mat chol(mat A);
}
