
#ifndef PHILIPS_WAVE_MODEL_HPP_
#define PHILIPS_WAVE_MODEL_HPP_
#include <iostream>
#include "WaveModel.h"

typedef struct List List;
struct List
{
    PhilipsWave* wave;
    List *next;
};


class PḧilipsWaveModel : public WaveModel {
public:
	~PhilipsWaveModel();
	PhilipsWaveModel(double direction[2], double, double, double);
	PhilipsWaveModel(const PhilipsWaveModel &);
	List* getWaveList() const;
	void addWave(PhilipsWave) ;
	double operator()(int, int, double) const ;
private:
  List *waveList;

};

#endif
