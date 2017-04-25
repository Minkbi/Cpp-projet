
#ifndef GERSTNER_WAVE_MODEL_HPP_
#define GERSTNER_WAVE_MODEL_HPP_
#include <iostream>
#include "WaveModel.h"

class GerstnerWaveModel : public WaveModel {
public:
  GerstnerWaveModel(double direction[3], double, double, double);
  GerstnerWaveModel(const GerstnerWaveModel &);
};

#endif
