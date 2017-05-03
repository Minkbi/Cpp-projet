#ifndef GERSTNER_WAVE_HPP_
#define GERSTNER_WAVE_HPP_
#include <iostream>
#include "Dvector.h"
#include "Error.h"

class GerstnerWave {
public:
  GerstnerWave(Dvector, double, double, double);
  GerstnerWave(const GerstnerWave &);
  Dvector getDirection() const;
  double getAmplitude() const;
  double getPhase() const;
  double getFrequence() const;
protected:
  Dvector direction;
  double amplitude;
  double phase;
  double frequence;
};

#endif
