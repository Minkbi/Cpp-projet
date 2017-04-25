
#ifndef GERSTNER_WAVE_MODEL_HPP_
#define GERSTNER_WAVE_MODEL_HPP_
#include <iostream>
#include "WaveModel.h"
#include "GerstnerWave.h"
typedef struct List List;
struct List
{
    GerstnerWave* wave;
    List *next;
};


class GerstnerWaveModel : public WaveModel {
public:
	~GerstnerWaveModel();
	GerstnerWaveModel(double direction[2], double, double, double);
	GerstnerWaveModel(const GerstnerWaveModel &);
	List* getWaveList() const;
	void addWave(GerstnerWave) ;
	double operator()(int, int, double) const ;
private:
  List *waveList;

};

#endif
