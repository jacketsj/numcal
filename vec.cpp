#include "vec.h"

vec::vec() : d(0), vals(0) {}

vec::vec(int d) : d(d), vals(d) {}

vec::vec(vector<num> vals)  : d(vals.size()), vals(vals) {}

vec::vec(const vec &oth)
{
	d = oth.d;
	vals = oth.vals;
}
	
void vec::operator=(const vec &oth)
{
	d = oth.d;
	vals.resize(d);
	//vals = oth.vals;
	for (int i = 0; i < d; ++i)
		vals[i] = oth.roa(i);
}


bool vec::operator==(const vec &oth) const
{
	return d == d && vals == oth.vals;
}


vec vec::operator+(num oth) const
{
	vec ret = *this;
	ret += oth;
	return ret;
}

vec vec::operator-(num oth) const
{
	vec ret = *this;
	ret -= oth;
	return ret;
}

vec vec::operator*(num oth) const
{
	vec ret = *this;
	ret *= oth;
	return ret;
}

vec vec::operator/(num oth) const
{
	vec ret = *this;
	ret /= oth;
	return ret;
}

vec vec::operator^(num oth) const
{
	vec ret = *this;
	ret ^= oth;
	return ret;
}


vec operator+(num oth, const vec &v)
{
	return v + oth;
}

vec operator-(num oth, const vec &v)
{
	return v - oth;
}

vec operator*(num oth, const vec &v)
{
	return v * oth;
}


void vec::operator+=(num oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] += oth;
}

void vec::operator-=(num oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] -= oth;
}

void vec::operator*=(num oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] *= oth;
}

void vec::operator/=(num oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] /= oth;
}

void vec::operator^=(num oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] = pow(vals[i],oth);
}


vec vec::operator+(const vec &oth) const
{
	vec ret = *this;
	ret += oth;
	return ret;
}

vec vec::operator-(const vec &oth) const
{
	vec ret = *this;
	ret -= oth;
	return ret;
}


void vec::operator+=(const vec &oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] += oth.vals[i];
}

void vec::operator-=(const vec &oth)
{
	for (int i = 0; i < d; ++i)
		vals[i] -= oth.vals[i];
}

num vec::operator*(const vec &oth) const
{
	num ret = 0;
	for (int i = 0; i < d; ++i)
		ret += vals[i]*oth.vals[i];
	return ret;
}

num vec::norm() const
{
	return sqrt(norm2());
}

num vec::norm2() const
{
	return (*this)*(*this);
}

num vec::norm1() const
{
	return (*this)*one(d);
}

num vec::norm_inf() const
{
	num ret = 0;
	for (int i = 0; i < d; ++i) {
		num f = abs(vals[i]);
		if (f > ret)
			ret = f;
	}
	return ret;
}

string vec::to_string() const
{
	string ret="(";
	for (int i = 0; i < d; ++i)
	{
		ret += std::to_string(vals[i]);
		if (i+1 < d)
			ret += ",";
	}
	ret += ")";
	return ret;
}

num& vec::operator[](int i)
{
	return vals[i];
}

const num& vec::roa(int i) const
{
	return vals[i];
}

vec vec::same(int d, num val)
{
	vec ret(d);
	ret += val;
	return ret;
}

vec vec::one(int d)
{
	return same(d,1);
}

vec vec::zero(int d)
{
	return same(d,0);
}

vec vec::card(int d, int i)
{
	vec ret = zero(d);
	ret[i] = 1;
	return ret;
}

int vec::dim() const
{
	return d;
}
