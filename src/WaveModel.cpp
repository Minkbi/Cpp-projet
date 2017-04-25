#include "WaveModel.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

WaveModel::WaveModel(double *d, double ali, double i, double aju) {
  direction = d;
  alignement = ali;
  intensite = i;
  ajustement = aju;
}

WaveModel::WaveModel(const WaveModel &w) {
  direction = w.getDirection();
  alignement = w.getAlignement();
  intensite = w.getIntensite();
  ajustement = w.getAjustement();
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
