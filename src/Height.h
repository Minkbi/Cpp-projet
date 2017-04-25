#ifndef HEIGHT_HPP_
#define HEIGHT_HPP_
#include <iostream>

class Height {
public:
  Height(double, double, int, int);
  Height(const Height &);
  ~Height();
  void set(double, int, int);
  double& operator()(int, int) const;
  int sizex() const;
  int sizey() const;
  double taillex() const;
  double tailley() const;

private:
  double lx;
  double ly;
  int nx;
  int ny;
  double **mat;
};

#endif
