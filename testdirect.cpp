#include <iostream>
#include "direct.h"
#include "mat.h"
#include "vec.h"

using namespace std;

using namespace direct;

// test gaussian elimination
int main()
{
	int d = 3;
	mat A(d,d);
	A[0] = vec({1,-4,3});
	A[1] = vec({1,1,0});
	A[2] = vec({3,-2,1});

	vec b({-2,5,6});

	cout << "solving: " << A.to_string() << "*x=" << b.to_string() << endl;

	cout << "result: x=" << ge(A,b).to_string() << endl;
	cout << "solving: " << A.to_string() << "*x=" << b.to_string() << endl;

	cout << "with gepp: x=" << gepp(A,b).to_string() << endl;
	A[0] = vec({1,1,1});
	A[1] = vec({1,1,2});
	A[2] = vec({1,2,2});

	mat P, L, U;

	plu(A,P,L,U);

	cout << "with A=" << A.to_string() << ", we get\n"
		<< "P=" << P.to_string() << "\n"
		<< "L=" << L.to_string() << "\n"
		<< "U=" << U.to_string() << "\n";
}
