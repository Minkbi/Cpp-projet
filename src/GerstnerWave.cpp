#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(double *d, double a, double p, double f) {
  direction = d;
  amplitude = a;
  phase = p;
  frequence = f;
}

GerstnerWave::GerstnerWave(const GerstnerWave &g) {
  direction = g.getDirection();
  amplitude = g.getAmplitude();
  phase = g.getPhase();
  frequence = g.getFrequence();
}

double *GerstnerWave::getDirection() const {
	return direction;
}

double GerstnerWave::getAmplitude() const {
	return amplitude;
}

double GerstnerWave::getPhase() const {
	return phase;
}

double GerstnerWave::getFrequence() const {
	return frequence;
}
