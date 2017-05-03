#ifndef DVECTOR_HPP_
#define DVECTOR_HPP_
#include <iostream>
#include "Error.h"

class Dvector {
public:
	Dvector();
	Dvector(int, double);
	Dvector(int);
	Dvector(char *);
	Dvector(const Dvector&);
	virtual ~Dvector();
	void display(std::ostream&) const;
	int size() const;
	void fillRandomly();
	double& operator()(int) const;
	Dvector& operator=(Dvector);
	void set(int, double);

protected:
	int dim;
	double *vector;

};

Dvector operator+(const Dvector&, const Dvector&);
Dvector operator-(const Dvector&, const Dvector&);
double operator*(const Dvector&, const Dvector&);
Dvector operator+(const Dvector&, double);
Dvector operator-(const Dvector&, double);
Dvector operator*(const Dvector&, double);
Dvector operator/(const Dvector&, double);
void operator+=(Dvector& v1, double val);
void operator-=(Dvector& v1, double val);
void operator*=(Dvector& v1, double val);
void operator/=(Dvector& v1, double val);
void operator+=(Dvector& v1, const Dvector& v2);
void operator-=(Dvector& v1, const Dvector& v2);
Dvector operator-(const Dvector& v1);
std::ostream& operator<<(std::ostream& os, const Dvector& v);
std::istream& operator>>(std::istream& is, Dvector& obj);
bool operator==(const Dvector& v1, const Dvector& v2);
#endif
