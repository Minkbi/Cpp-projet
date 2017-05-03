
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
  virtual double operator()(int, int, double) const;


protected:
  Dvector direction;
  double alignement;
  double intensite;
  double ajustement;

};

typedef std::shared_ptr<WaveModel> WaveModelPtr;

#endif

