#include "PhilipsWave.h"

PhilipsWave::PhilipsWave(Dvector k, double a, double p, double f) {
  if (k.size() != 2) throw Error("la direction du vent doit être de dimension 2");
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

Dvector PhilipsWave::getDirection() const {
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
