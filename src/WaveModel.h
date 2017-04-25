#ifndef WAVE_MODEL_HPP_
#define WAVE_MODEL_HPP_
#include <iostream>

class WaveModel {
public:
  WaveModel(double direction[3], double, double, double);
  WaveModel(const WaveModel &);
  double *getDirection() const;
  double getAlignement() const;
  double getIntensite() const;
  double getAjustement() const;
protected:
  double *direction;
  double alignement;
  double intensite;
  double ajustement;
};

#endif
