#ifndef mat_h
#define mat_h

#include <string>
#include <vector>
#include <cmath>

#include "vec.h"

using namespace std;

struct mat
{
	mat();
	mat(int m, int n);
	mat(const mat &oth);
	mat(const vec &oth);
	void operator=(const mat &oth);

	bool operator==(const mat &oth) const;

	mat operator+(num oth) const;
	mat operator-(num oth) const;
	mat operator*(num oth) const;
	mat operator/(num oth) const;

	//TODO
	//mat operator^(int k) const;

	void operator+=(num oth);
	void operator-=(num oth);
	void operator*=(num oth);
	void operator/=(num oth);

	vec operator*(const vec &oth) const;

	mat operator+(const mat &oth) const;
	mat operator-(const mat &oth) const;

	mat operator*(const mat &oth) const;

	void operator+=(const mat &oth);
	void operator-=(const mat &oth);

	void operator*=(const mat &oth);


	//num norm() const; // l2 norm
	//num norm2() const; // l2 norm squared
	num norm1() const; // l1 norm
	num norm_inf() const; // l-inf norm

	string to_string() const;

	vec& operator[](int i);
	const vec& roa(int i) const;
	const num& roa(int i, int j) const;

	mat t() const;

	vec diag() const;

	int dim(int i) const;

	static mat same(int m, int n, num val);
	static mat one(int m, int n);
	static mat zero(int m, int n);
	static mat diag(const vec &oth);

private:
	int m, n;
	vector<vec> vals; //vector of rows
};

#endif
