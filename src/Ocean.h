#ifndef OCEAN_HPP_
#define OCEAN_HPP_

#include "GerstnerWaveModel.h"
#include "Height.h"

class Ocean {
 public:
  Ocean(double,double,int,int,GerstnerWaveModel,Height);
  ~Ocean();
  void init_gl_VertexArrayX(const int y, double* const vertices) const;
  void init_gl_VertexArrayY(const int x, double* const vertices) const;
  void gl_VertexArrayX(const int y, double* const vertices) const;
  void gl_VertexArrayY(const int x, double* const vertices) const;
  int getNx() const;
  int getNy() const;
  double get_lx() const;
  double get_ly() const;
  void main_computation();
 
 private:
  double lx;
  double ly;
  int nx;
  int ny;
  double t;
  Height H;
  GerstnerWaveModel model;


};

#endif

