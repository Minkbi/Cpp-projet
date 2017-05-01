#include "PhilipsWave.h"

PhilipsWave::PhilipsWave(double *k, double a, double p, double f) {
  direction = k;
  amplitude = a;
  phase = p;
  frequence = f;
}

PhilipsWave::PhilipsWave(const PhilipsWave &g) {
  direction = g.getDirection();
  amplitude = g.getAmplitude();
  phase = g.getPhase();
  frequence = g.getFrequence();
}

double *PhilipsWave::getDirection() const {
	return direction;
}

double PhilipsWave::getAmplitude() const {
	return amplitude;
}

double PhilipsWave::getPhase() const {
	return phase;
}

double PhilipsWave::getFrequence() const {
	return frequence;
}
