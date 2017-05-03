
#ifndef GERSTNER_WAVE_MODEL_HPP_
#define GERSTNER_WAVE_MODEL_HPP_
#include <iostream>
#include "WaveModel.h"
#include "GerstnerWave.h"

typedef struct ListGerstner ListGerstner;
struct ListGerstner
{
  GerstnerWave *wave;
  ListGerstner *next;
};


class GerstnerWaveModel : public WaveModel {
 public:
  ~GerstnerWaveModel();
  GerstnerWaveModel(Dvector direction, double, double, double);
  GerstnerWaveModel(const GerstnerWaveModel &);
  ListGerstner* getWaveList() const;
  void addWave(GerstnerWave);
  double operator()(int, int, double) const override;
  void compute(double, Height*) const override;
 private:
  ListGerstner *waveList;

};

#endif
