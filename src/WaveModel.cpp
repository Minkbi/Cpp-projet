#include "WaveModel.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

WaveModel::WaveModel(double *d, double ali, double i, double aju) {
  direction = d;
  alignement = ali;
  intensite = i;
  ajustement = aju;
  height= new Height(1,1,1,1);
}

WaveModel::WaveModel(const WaveModel &w) {
  direction = w.getDirection();
  alignement = w.getAlignement();
  intensite = w.getIntensite();
  ajustement = w.getAjustement();
  height = new Height(w.getHeight());
}

double * WaveModel::getDirection() const {
  return direction;
}

double WaveModel::getAlignement() const {
  return alignement;
}

double WaveModel::getIntensite() const {
  return intensite;
}

double WaveModel::getAjustement() const {
  return ajustement;
}

const Height& WaveModel::getHeight() const {
	return height;
}

double& WaveModel::operator()(int x, int y, double t) const {
  return  height(x,y);
}
