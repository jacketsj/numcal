#include <iostream>
#include "opt.h"
#include "direct.h"
#include "mat.h"
#include "vec.h"

using namespace std;

using namespace opt;
using namespace direct;

// test optimization
int main()
{
	mat A(3,3);
	A[0] = vec({100,3,-2});
	A[1] = vec({1,200,5});
	A[2] = vec({-4,3,100});
	vec b({800,1000,500});

	num tol = 1e-8;

	vec res = steep(A,b,tol);
	cout << "ans=" << res.to_string() << endl;
	cout << "diff: " << (res-ge(A,b)).norm() << endl;
}
