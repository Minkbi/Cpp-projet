
#ifndef PHILIPS_WAVE_MODEL_HPP_
#define PHILIPS_WAVE_MODEL_HPP_
#include <iostream>
#include <cmath>
#include "WaveModel.h"
#include "PhilipsWave.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

/* 
   RAND is a macro which returns a pseudo-random numbers from a uniform
   distribution on the interval [0 1]
*/

//srand(time(NULL));
#define RAND ((double) rand())/((double) RAND_MAX)
 
/*
   TWOPI = 2.0*pi
*/
#define TWOPI 2.0*3.141592653589793238462643383279502884197169399375
 
/* 
   RANDN is a macro which returns a pseudo-random numbers from a normal
   distribution with mean zero and standard deviation one. This macro uses Box
   Muller's algorithm
*/
#define RANDN sqrt(-2.0*log(RAND))*cos(TWOPI*RAND)

typedef struct List List;
struct List
{
    PhilipsWave* wave;
    List *next;
};

class PhilipsWaveModel : public WaveModel {
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
