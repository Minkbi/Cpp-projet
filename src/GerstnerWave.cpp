#include "GerstnerWave.h"

GerstnerWave::GerstnerWave(Dvector d, double a, double p, double f) {
  if (d.size() != 2) throw Error("la direction du vent doit être de dimension 2");
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

Dvector GerstnerWave::getDirection() const {
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
