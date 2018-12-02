#ifndef vec_h
#define vec_h

#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define num double

struct vec
{
	vec();
	vec(int d);
	vec(int d, vector<num> vals);
	vec(const vec &oth);
	void operator=(const vec &oth);

	bool operator==(const vec &oth) const;

	vec operator+(num oth) const;
	vec operator-(num oth) const;
	vec operator*(num oth) const;
	vec operator/(num oth) const;
	vec operator^(num oth) const;

	void operator+=(num oth);
	void operator-=(num oth);
	void operator*=(num oth);
	void operator/=(num oth);
	void operator^=(num oth);

	vec operator+(const vec &oth) const;
	vec operator-(const vec &oth) const;

	void operator+=(const vec &oth);
	void operator-=(const vec &oth);

	num operator*(const vec &oth) const; // dot product

	num norm() const; // l2 norm
	num norm2() const; // l2 norm squared
	num norm1() const; // l1 norm
	num norm_inf() const; // l-inf norm

	string to_string() const;

	num& operator[](int i);
	const num& roa(int i) const;

	int dim() const;

	static vec same(int d, num val);
	static vec one(int d);
	static vec zero(int d);
	static vec card(int d, int i); //cardinal vector in direction i

private:
	int d;
	vector<num> vals;
};

#endif
