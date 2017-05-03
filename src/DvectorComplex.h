#ifndef DVECTORCOMPLEX_HPP_
#define DVECTORCOMPLEX_HPP_
#include <iostream>
#include "Error.h"
#include <complex>

class DvectorComplex {
public:
	DvectorComplex();
	DvectorComplex(int, complex<double>);
	DvectorComplex(int);
	DvectorComplex(const DvectorComplex&);
	virtual ~DvectorComplex();
	void display(ostream&) const;
	int size() const;
	void fillRandomly();
	complex<double>& operator()(int) const;
	DvectorComplex& operator=(DvectorComplex);
	void set(int, complex<double>);
	void conjVect();

protected:
	int dim;
	complex<double> *vector;

};

DvectorComplex operator+(const DvectorComplex&, const DvectorComplex&);
DvectorComplex operator-(const DvectorComplex&, const DvectorComplex&);
complex<double> operator*(const DvectorComplex&, const DvectorComplex&);
DvectorComplex operator+(const DvectorComplex&, complex<double>);
DvectorComplex operator-(const DvectorComplex&, complex<double>);
DvectorComplex operator*(const DvectorComplex&, complex<double>);
DvectorComplex operator/(const DvectorComplex&, complex<double>);
void operator+=(DvectorComplex& v1, complex<double> val);
void operator-=(DvectorComplex& v1, complex<double> val);
void operator*=(DvectorComplex& v1, complex<double> val);
void operator/=(DvectorComplex& v1, complex<double> val);
void operator+=(DvectorComplex& v1, const DvectorComplex& v2);
void operator-=(DvectorComplex& v1, const DvectorComplex& v2);
DvectorComplex operator-(const DvectorComplex& v1);
ostream& operator<<(ostream& os, const DvectorComplex& v);
istream& operator>>(istream& is, DvectorComplex& obj);
bool operator==(const DvectorComplex& v1, const DvectorComplex& v2);
#endif
