
#ifndef PHILIPS_WAVE_MODEL_HPP_
#define PHILIPS_WAVE_MODEL_HPP_
#include <iostream>
#include <cmath>
#include "WaveModel.h"
#include "Ftransform.h"
#include "HeightComplex.h"
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
   RANDN is a macro which returns a pseudo-random numbers from a normal
   distribution with mean zero and standard deviation one. This macro uses Box
   Muller's algorithm
*/
#define RANDN sqrt(-2.0*log(RAND))*cos(TWOPI*RAND)

class PhilipsWaveModel : public WaveModel {
 public:
  ~PhilipsWaveModel();
  PhilipsWaveModel(Dvector, double, double, double);
  PhilipsWaveModel(const PhilipsWaveModel &);
  complex<double> calc(double, double, double) const;
  void compute(double, Height*) const override;
 private:
};

#endif
