#include "GerstnerWaveModel.h"
#include <cmath>

GerstnerWaveModel::GerstnerWaveModel(double *d, double ali, double i, double aju) : WaveModel(d, ali, i, aju){
	waveList = NULL;

}

GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel &w) : WaveModel(w) {
	waveList = NULL;
	List *cour = w.getWaveList();
	List *temp = NULL;
	while(cour!=NULL){
		temp = new struct List;
		temp->wave = new GerstnerWave(cour->wave);
		temp->next = waveList;
		waveList = temp;
		cour = cour->next;
	}

}

void GerstnerWaveModel::addWave(GerstnerWave newWave) {
	List *temp = new struct List;
	temp->wave = new GerstnerWave(newWave);
	temp->next = waveList;
	waveList = temp;
}


const List& GerstnerWaveModel::getWaveList() const {
	return waveList;
}


double& GerstnerWaveModel::operator()(int x, int y, double t) const {
	int z = height (x,y);
	List *cour = waveList;
	while(cour !=NULL){
		z += cour->wave.getAmplitude() * cos(cour->wave.getDirection()[0] * x
				+ cour->wave.getDirection()[1] * y // pas sur
				- cour->wave.getFrequence()* t +cour->wave.getPhase() );
	}

  return  z;
}
