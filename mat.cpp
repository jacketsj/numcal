#include <cassert>
#include "mat.h"

mat::mat() : m(0), n(0), vals() {}

mat::mat(int m, int n) : m(m), n(n), vals()
{
	for (int i = 0; i < m; ++i)
		vals.push_back(vec(n));
}

mat::mat(const mat &oth) : m(oth.m), n(oth.n), vals(oth.vals) {}

void mat::operator=(const mat &oth)
{
	n = oth.n;
	m = oth.m;
	vals = oth.vals;
}

mat::mat(const vec &oth) : m(oth.dim()), n(1), vals(m)
{
	for (int i = 0; i < m; ++i)
		vals[i] = vec(1);
	for (int i = 0; i < m; ++i)
		(*this)[i][0] = oth.roa(i);
}

bool mat::operator==(const mat &oth) const
{
	return n == oth.n && m == oth.m && vals == oth.vals;
}

mat mat::operator+(num oth) const
{
	mat ret = *this;
	ret += oth;
	return ret;
}
mat mat::operator-(num oth) const
{
	mat ret = *this;
	ret -= oth;
	return ret;
}
mat mat::operator*(num oth) const
{
	mat ret = *this;
	ret *= oth;
	return ret;
}
mat mat::operator/(num oth) const
{
	mat ret = *this;
	ret /= oth;
	return ret;
}

mat mat::operator^(unsigned k) const
{
	int d = m;
	assert (d == n);
	mat ret = iden(d);
	mat exp = (*this);
	for (; k > 0; k /= 2)
	{
		if (k % 2 == 1)
			ret *= exp;
		exp *= exp;
	}
	return ret;
}

void mat::operator+=(num oth)
{
	for (auto& a : vals)
		a += oth;
}
void mat::operator-=(num oth)
{
	for (auto& a : vals)
		a -= oth;
}
void mat::operator*=(num oth)
{
	for (auto& a : vals)
		a *= oth;
}
void mat::operator/=(num oth)
{
	for (auto& a : vals)
		a /= oth;
}

void mat::operator^=(unsigned k)
{
	(*this) = (*this) ^ k;
}

vec mat::operator*(const vec &oth) const
{
	vec ret(m);
	for (int i = 0; i < m; ++i)
		ret[i] = roa(i)*oth;
	return ret;
}

mat mat::operator+(const mat &oth) const
{
	mat ret = *this;
	ret += oth;
	return ret;
}

mat mat::operator-(const mat &oth) const
{
	mat ret = *this;
	ret -= oth;
	return ret;
}

mat mat::operator*(const mat &oth) const
{
	mat otht = oth.t();
	mat ret(m, otht.m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < otht.m; ++j)
			ret[i][j] = roa(i)*otht[j];
	return ret;
}

void mat::operator+=(const mat &oth)
{
	for (int i = 0; i < m; ++i)
		(*this)[i] += oth.roa(i);
}

void mat::operator-=(const mat &oth)
{
	for (int i = 0; i < m; ++i)
		(*this)[i] -= oth.roa(i);
}

void mat::operator*=(const mat &oth)
{
	(*this) = (*this)*oth;
}

//TODO after svd
//num mat::norm() const
//num mat::norm2() const
num mat::norm1() const
{
	return t().norm_inf();
}
num mat::norm_inf() const
{
	num ret = 0;
	for (int i = 0; i < m; ++i)
	{
		num v = roa(i).norm1();
		if (v > ret)
			ret = v;
	}
	return ret;
}

string mat::to_string() const
{
	string ret="(";
	for (int i = 0; i < m; ++i)
	{
		ret += roa(i).to_string();
		if (i+1 < m)
			ret += ",";
	}
	ret += ")";
	return ret;
}

vec& mat::operator[](int i)
{
	return vals[i];
}

const vec& mat::roa(int i) const
{
	return vals[i];
}

const num& mat::roa(int i, int j) const
{
	return vals[i].roa(j);
}

mat mat::t() const
{
	mat ret(n, m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			ret[j][i] = roa(i,j);
	return ret;
}

vec mat::diag() const
{
	assert(m==n);
	int d = m;
	vec ret(d);
	for (int i = 0; i < d; ++i)
		ret[i] = roa(i,i);
	return ret;
}

int mat::dim(int i) const
{
	if (i)
		return n;
	return m;
}

mat mat::iden(int d)
{
	return diag(vec::one(d));
}

mat mat::same(int m, int n, num val)
{
	mat ret(m,n);
	ret += val;
	return ret;
}

mat mat::one(int m, int n)
{
	return same(m,n,1);
}

mat mat::zero(int m, int n)
{
	return same(m,n,0);
}
mat mat::diag(const vec &oth)
{
	int d = oth.dim();
	mat ret = zero(d, d);
	for (int i = 0; i < d; ++i)
		ret[i][i] = oth.roa(i);
	return ret;
}
