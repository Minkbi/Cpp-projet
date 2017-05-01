#ifndef PHILIPS_WAVE_HPP_
#define PHILIPS_WAVE_HPP_
#include <iostream>

class PhilipsWave {
public:
  PhilipsWave(double *, double, double, double);
  PhilipsWave(const PhilipsWave &);
  double *getDirection() const;
  double getAmplitude() const;
  double getPhase() const;
  double getFrequence() const;
protected:
  double *direction;
  double amplitude;
  double phase;
  double frequence;
};

#endif
