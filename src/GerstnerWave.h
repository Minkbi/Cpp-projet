#ifndef GERSTNER_WAVE_HPP_
#define GERSTNER_WAVE_HPP_
#include <iostream>

class GerstnerWave {
public:
  GerstnerWave(double *, double, double, double);
  GerstnerWave(const GerstnerWave &);
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
