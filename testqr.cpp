#include <iostream>
#include "qr.h"
#include "mat.h"
#include "vec.h"

using namespace std;

using namespace qr;

// test qr decomposition
int main()
{
	mat A(4,3);
	A[0] = vec({1,-1,4});
	A[1] = vec({1,4,-2});
	A[2] = vec({1,4,2});
	A[3] = vec({1,-1,0});

	mat R;
	mat Q = gs(A,R);
	cout << "QR decomposition of A=" << A.to_string() << "is\n"
		<< "Q=" << Q.to_string() << endl
		<< "R=" << R.to_string() << endl;
}
