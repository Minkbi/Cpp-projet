#ifndef PHILIPS_WAVE_HPP_
#define PHILIPS_WAVE_HPP_
#include <iostream>
#include "Dvector.h"
#include "Error.h"

class PhilipsWave {
public:
  PhilipsWave(Dvector, double, double, double);
  PhilipsWave(const PhilipsWave &);
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
