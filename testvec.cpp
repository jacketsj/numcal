#include <iostream>
#include "vec.h"

using namespace std;

// test basic vector operations
int main()
{
	int d = 4;
	vec a(d), b(d);
	for (int i = 0; i < d; ++i)
		a[i] = b[i] = i;
	a += b;
	cout << "sum: " << (a+b).to_string() << endl;
	cout << "dot product: " << a*b << endl;
}
