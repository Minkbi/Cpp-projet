#include "WaveModel.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

WaveModel::WaveModel(Dvector d, double ali, double i, double aju) {
  if (d.size() != 2) throw Error("la direction du vent doit être de dimension 2");
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

Dvector WaveModel::getDirection() const {
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

double WaveModel::operator()(int, int, double) const {
  return ajustement;
}

void WaveModel::compute(double, Height*) const {}
