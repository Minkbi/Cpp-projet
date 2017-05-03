#ifndef HEIGHT_COMPLEX_HPP_
#define HEIGHT_COMPLEX_HPP_


#include <iostream>
#include <complex>

#include "Height.h"

class HeightComplex {
public:
  HeightComplex(double, double, int, int);
  HeightComplex(const HeightComplex &);
  HeightComplex(const Height &);
  ~HeightComplex();
  void set(std::complex<double>, int, int);
  std::complex<double>& operator()(int, int) const;
  int sizex() const;
  int sizey() const;
  double taillex() const;
  double tailley() const;
  HeightComplex operator=(HeightComplex);

private:
  double lx;
  double ly;
  int nx;
  int ny;
  std::complex<double> **mat;
};

#endif
