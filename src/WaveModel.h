
#ifndef WAVE_MODEL_HPP_
#define WAVE_MODEL_HPP_
#include <iostream>
#include <memory>
#include "Height.h"
#include "Dvector.h"
#include "Error.h"

class WaveModel {
public:
  WaveModel(Dvector direction, double, double, double);
  WaveModel(const WaveModel &);
  //virtual ~WaveModel();
  Dvector getDirection() const;
  double getAlignement() const;
  double getIntensite() const;
  double getAjustement() const;
  virtual void compute(double, Height*) const = 0;

protected:
  Dvector direction;
  double alignement;
  double intensite;
  double ajustement;
};

typedef std::shared_ptr<WaveModel> WaveModelPtr;

#endif

