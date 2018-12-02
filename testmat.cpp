#include <iostream>
#include "mat.h"
#include "vec.h"

using namespace std;

// test basic matrix operations
int main()
{
	int d = 4;
	vec a(d), b(d);
	for (int i = 0; i < d; ++i)
		a[i] = b[i] = i;
	cout << "dot product: " << a*b << endl;
	mat am = mat(a);
	mat tr = am.t();
	vec res = mat(a).t() * b;
	//cout << "dot product: " << ((mat(a).t())*b).roa(0) << endl;
	cout << "dot product: " << res.to_string() << endl;
	cout << "dimensions: (" << tr.dim(0) << "," << tr.dim(1) << ")" << endl;
	cout << "tr: " << tr.to_string() << endl;
	cout << "am: " << am.to_string() << endl;
}
