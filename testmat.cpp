#include <iostream>
#include "mat.h"
#include "vec.h"

using namespace std;

// test basic matrix operations
int main()
{
	//norm computation using (a^T)*(b)
	int d = 4;
	vec a(d), b(d);
	for (int i = 0; i < d; ++i)
		a[i] = b[i] = i;
	cout << "dot product: " << a*b << endl;
	cout << "dot product: " << ((mat(a).t())*b).to_string() << endl;

	//fibonacci number computation
	mat fib(4,4);
	fib[0][0] = 0;
	fib[0][1] = 1;
	fib[1][0] = 1;
	fib[1][1] = 1;
	vec f01(2);
	f01[0] = 1;
	f01[1] = 1;
	cout << "3rd fibonacci number: " << (fib*f01)[1] << endl;
}
