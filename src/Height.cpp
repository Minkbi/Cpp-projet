#include "Height.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

Height::Height(double taillex, double tailley, int nombrex, int nombrey){
  lx = taillex;
  ly = tailley;
  nx = nombrex;
  ny = nombrey;
  mat = new double*[nx];
  for (int i=0; i<nx; i++) {
    mat[i] = new double[ny];
    for (int j=0; j<ny; j++) {
      mat[i][j] = 0;
    }
  } 
}

Height::Height(const Height &h){
  lx = h.taillex();
  ly = h.tailley();
  nx = h.sizex();
  ny = h.sizey();
  mat = new double*[nx];
  for (int i=0; i<nx; i++) {
    mat[i] = new double[ny];
    for (int j=0; j<ny; j++){
    	mat[i][j] = h(i,j);
    }
  } 
}

Height::~Height() {
  if (mat != NULL) {
    for (int i = 0; i < nx; i++) {
      if (mat[i] != NULL) {
	delete mat[i];
      }  
    }
    delete mat;
  }

}

void Height::set(double val, int x, int y) {
  mat[x][y] = val;
}

double& Height::operator()(int x, int y) const {
  return  mat[x][y];
}

int Height::sizex() const {
  return nx;
}

int Height::sizey() const {
  return ny;
}

double Height::taillex() const {
  return lx;
}

double Height::tailley() const {
  return ly;
}

Height Height::operator=(Height h) {
	lx = h.taillex();
	ly = h.tailley();
	nx = h.sizex();
	ny = h.sizey();
	mat = new double*[nx];
	for (int i=0; i<nx; i++) {
	mat[i] = new double[ny];
		for (int j=0; j<ny; j++){
			mat[i][j] = h(i,j);
		}
  }
  return *this;
}


