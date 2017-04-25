#ifndef WAVE_MODEL_HPP_
#define WAVE_MODEL_HPP_
#include <iostream>
#include "Height.h"

class WaveModel {
public:
  WaveModel(double direction[3], double, double, double);
  //pourquoi direction 3 ?
  WaveModel(const WaveModel &);
  double *getDirection() const;
  double getAlignement() const;
  double getIntensite() const;
  double getAjustement() const;
  double& operator()(int, int, double) const;
  const Height& getHeight() const;

protected:
  double *direction;
  double alignement;
  double intensite;
  double ajustement;
  Height height;
};

#endif
