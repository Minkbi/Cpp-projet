#include "HeightComplex.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

HeightComplex::HeightComplex(double taillex, double tailley, int nombrex, int nombrey){
  lx = taillex;
  ly = tailley;
  nx = nombrex;
  ny = nombrey;
  mat = new std::complex<double>*[nx];
  for (int i=0; i<nx; i++) {
    mat[i] = new std::complex<double>[ny];
    for (int j=0; j<ny; j++) {
      mat[i][j] = 0;
    }
  } 
}

HeightComplex::HeightComplex(const HeightComplex &h){
  lx = h.taillex();
  ly = h.tailley();
  nx = h.sizex();
  ny = h.sizey();
  mat = new std::complex<double>*[nx];
  for (int i=0; i<nx; i++) {
    mat[i] = new std::complex<double>[ny];
    for (int j=0; j<ny; j++){
    	mat[i][j] = h(i,j);
    }
  } 
}

HeightComplex::HeightComplex(const Height &h){
  lx = h.taillex();
  ly = h.tailley();
  nx = h.sizex();
  ny = h.sizey();
  mat = new std::complex<double>*[nx];
  for (int i=0; i<nx; i++) {
    mat[i] = new std::complex<double>[ny];
    for (int j=0; j<ny; j++){
    	mat[i][j] = h(i,j);
    }
  } 
}

HeightComplex::~HeightComplex() {
  if (mat != NULL) {
    for (int i = 0; i < nx; i++) {
      if (mat[i] != NULL) {
	delete mat[i];
      }  
    }
    delete mat;
  }

}

void HeightComplex::set(std::complex<double> val, int x, int y) {
  mat[x][y] = val;
}

std::complex<double>& HeightComplex::operator()(int x, int y) const {
  return  mat[x][y];
}

int HeightComplex::sizex() const {
  return nx;
}

int HeightComplex::sizey() const {
  return ny;
}

double HeightComplex::taillex() const {
  return lx;
}

double HeightComplex::tailley() const {
  return ly;
}

HeightComplex HeightComplex::operator=(HeightComplex h) {
	lx = h.taillex();
	ly = h.tailley();
	nx = h.sizex();
	ny = h.sizey();
	mat = new std::complex<double>*[nx];
	for (int i=0; i<nx; i++) {
	mat[i] = new std::complex<double>[ny];
		for (int j=0; j<ny; j++){
			mat[i][j] = h(i,j);
		}
  }
  return *this;
}


