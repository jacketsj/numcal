#include "mat.h"
#include "vec.h"

namespace direct
{
	// gives x from Ax=b
	// using basic gaussian elimination then backprop
	// assume A is not rank deficient
	vec ge(mat A, vec b);

	// gives x from Ax=b directly, where A is upper triangular
	vec backsub(mat A, vec b);
}
