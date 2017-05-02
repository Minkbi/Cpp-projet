#include "PhilipsWaveModel.h"
#include <cmath>



PhilipsWaveModel::~PhilipsWaveModel(){
	List* cour = waveList;
	List* temp = waveList;
	while (cour!=NULL){
		delete cour->wave;
		temp = cour;
		cour = cour->next;
		delete temp	;


	}
}

PhilipsWaveModel::PhilipsWaveModel(double *d, double ali, double i, double aju) : WaveModel(d, ali, i, aju){
	waveList = NULL;

}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &w) : WaveModel(w) {
	waveList = NULL;
	List *cour = w.getWaveList();
	List *temp = NULL;
	while(cour!=NULL){
		temp = new struct List;
		temp->wave = new PhilipsWave(*cour->wave);
		temp->next = waveList;
		waveList = temp;
		cour = cour->next;
	}

}

void PhilipsWaveModel::addWave(PhilipsWave newWave) {
	List *temp = new struct List;
	temp->wave = new PhilipsWave(newWave);
	temp->next = waveList;
	waveList = temp;
}


List* PhilipsWaveModel::getWaveList() const {
	return waveList;
}


double PhilipsWaveModel::operator()(int x, int y, double t) const {
  double z = ajustement; //hauteur moyenne / initiale
  List *cour = waveList;
  double res[2];
  double kx = TWOPI*x/10;
  double ky = TWOPI*y/10;
  double k = sqrt(kx*kx+ky*ky);
  while(cour !=NULL){
    double ampl = cour->wave->getAmplitude();
    //cour->wave->getPhase();
    double *dir = cour->wave->getDirection();
    double freq = cour->wave->getFrequence();
    double epsr = RANDN;
    double epsi = RANDN;
    double L = intensite*intensite/10;
    double Ph1 = ampl*exp(-1/(k*L)/(k*L))*(kx*dir[1]+ky*dir[2])*(kx*dir[1]+ky*dir[2])/(k*k);
    double Ph2 = ampl*exp(-1/(k*L)/(k*L))*(-kx*dir[1]-ky*dir[2])*(-kx*dir[1]-ky*dir[2])/(k*k);
    
    res[1] = sqrt(Ph1/2)*(epsr*cos(freq*t+kx*x+ky*y)-epsi*sin(freq*t+kx*x+ky*y));
    res[1] += sqrt(Ph2/2)*(epsr*cos(-freq*t+kx*x+ky*y)+epsi*sin(-freq*t+kx*x+ky*y));
    
    //res[2] = sqrt(Ph1/2)*(epsr*sin(freq*t+kx*x+ky*y)+epsi*cos(freq*t+kx*x+ky*y));
    //res[2] += sqrt(Ph2/2)*(epsr*sin(-freq*t+kx*x+ky*y)-epsi*cos(-freq*t+kx*x+ky*y));

    z += res[1];
    cour = cour->next;
  }
  return  z;
}
