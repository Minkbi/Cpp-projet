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
	while(cour !=NULL){
		z += cour->wave->getAmplitude() * cos(cour->wave->getDirection()[0] * x
				+ cour->wave->getDirection()[1] * y
				- cour->wave->getFrequence()* t +cour->wave->getPhase() );
	}

  return  z;
}
