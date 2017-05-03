#include "GerstnerWaveModel.h"
#include <cmath>
#include <cstdio>

GerstnerWaveModel::~GerstnerWaveModel(){
  ListGerstner* cour = waveList;
  ListGerstner* temp = waveList;
  while (cour!=NULL){
    delete cour->wave;
    temp = cour;
    cour = cour->next;
    delete temp;
  }
}

GerstnerWaveModel::GerstnerWaveModel(Dvector d, double ali, double i, double aju) : WaveModel(d, ali, i, aju){
  waveList = NULL;
}

GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel &w) : WaveModel(w) {
  waveList = NULL;
  ListGerstner *cour = w.getWaveList();
  ListGerstner *temp = NULL;
  while(cour!=NULL){
    temp = new struct ListGerstner;
    temp->wave = new GerstnerWave(*cour->wave);
    temp->next = waveList;
    waveList = temp;
    cour = cour->next;
  }
}

void GerstnerWaveModel::addWave(GerstnerWave newWave) {
  ListGerstner *temp = new struct ListGerstner;
  temp->wave = new GerstnerWave(newWave);
  temp->next = waveList;
  waveList = temp;
}


ListGerstner* GerstnerWaveModel::getWaveList() const {
  return waveList;
}

double GerstnerWaveModel::operator()(int x, int y, double t) const {
  double z = ajustement; //hauteur moyenne / initiale
  ListGerstner *cour = waveList;
  while(cour !=NULL){
    z += cour->wave->getAmplitude() * cos(cour->wave->getDirection()(0) * x
					  + cour->wave->getDirection()(1) * y
					  - cour->wave->getFrequence()* t +cour->wave->getPhase() );
    cour = cour->next;
  }
  return  z;
}
