#include "PhilipsWaveModel.h"
#include <cmath>

PhilipsWaveModel::~PhilipsWaveModel(){
  ListPhilips* cour = waveList;
  ListPhilips* temp = waveList;
  while (cour!=NULL){
    delete cour->wave;
    temp = cour;
    cour = cour->next;
    delete temp	;


  }
}

PhilipsWaveModel::PhilipsWaveModel(Dvector d, double ali, double i, double aju) : WaveModel(d, ali, i, aju){
  waveList = NULL;

}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &w) : WaveModel(w) {
  waveList = NULL;
  ListPhilips *cour = w.getWaveList();
  ListPhilips *temp = NULL;
  while(cour!=NULL){
    temp = new struct ListPhilips;
    temp->wave = new PhilipsWave(*cour->wave);
    temp->next = waveList;
    waveList = temp;
    cour = cour->next;
  }

}

void PhilipsWaveModel::addWave(PhilipsWave newWave) {
  ListPhilips *temp = new struct ListPhilips;
  temp->wave = new PhilipsWave(newWave);
  temp->next = waveList;
  waveList = temp;
}


ListPhilips* PhilipsWaveModel::getWaveList() const {
  return waveList;
}


double PhilipsWaveModel::operator()(int x, int y, double t) const {
  
  double z = ajustement; //hauteur moyenne / initiale
  ListPhilips *cour = waveList;
  Dvector res(2);
  double kx = TWOPI*x/10;
  double ky = TWOPI*y/10;
  double k = sqrt(kx*kx+ky*ky);
  while(cour !=NULL){
    double ampl = cour->wave->getAmplitude();
    //cour->wave->getPhase();
    Dvector dir = cour->wave->getDirection();
    double freq = cour->wave->getFrequence();
    double epsr = RANDN;
    double epsi = RANDN;
    double L = dir(0)*dir(0)+dir(1)*dir(1)/10;
    double Ph1 = ampl*exp(-1/(k*L)/(k*L))*(kx*dir(0)+ky*dir(1))*(kx*dir(0)+ky*dir(1))/(k*k);
    double Ph2 = ampl*exp(-1/(k*L)/(k*L))*(-kx*dir(0)-ky*dir(1))*(-kx*dir(0)-ky*dir(1))/(k*k);
    
    res(0) = sqrt(Ph1/2)*(epsr*cos(freq*t+kx*x+ky*y)-epsi*sin(freq*t+kx*x+ky*y));
    res(0) += sqrt(Ph2/2)*(epsr*cos(-freq*t+kx*x+ky*y)+epsi*sin(-freq*t+kx*x+ky*y));
    
    //res(1) = sqrt(Ph1/2)*(epsr*sin(freq*t+kx*x+ky*y)+epsi*cos(freq*t+kx*x+ky*y));
    //res(1) += sqrt(Ph2/2)*(epsr*sin(-freq*t+kx*x+ky*y)-epsi*cos(-freq*t+kx*x+ky*y));

    z += res(0);
    cour = cour->next;
  }
  return  z;
}

void PhilipsWaveModel::compute(double t, Height *H) const {  

  HeightComplex Hcomplex(*H);
  
  for (int x = 0 ; x < Hcomplex.sizex() ; x++) {
    for (int y = 0 ; y < Hcomplex.sizey() ; y++) {
      ListPhilips *cour = waveList;
      Dvector res(2);
      res(0) = ajustement;
      res(1) = ajustement;
      double kx = TWOPI*x/10;
      double ky = TWOPI*y/10;
      double k = sqrt(kx*kx+ky*ky);
      while(cour !=NULL){
	double ampl = cour->wave->getAmplitude();
	//cour->wave->getPhase();
	Dvector dir = cour->wave->getDirection();
	double freq = cour->wave->getFrequence();
	double epsr = RANDN;
	double epsi = RANDN;
	double L = dir(0)*dir(0)+dir(1)*dir(1)/10;
	double Ph1 = ampl*exp(-1/(k*L)/(k*L))*(kx*dir(0)+ky*dir(1))*(kx*dir(0)+ky*dir(1))/(k*k);
	double Ph2 = ampl*exp(-1/(k*L)/(k*L))*(-kx*dir(0)-ky*dir(1))*(-kx*dir(0)-ky*dir(1))/(k*k);
    
	res(0) += sqrt(Ph1/2)*(epsr*cos(freq*t+kx*x+ky*y)-epsi*sin(freq*t+kx*x+ky*y));
	res(0) += sqrt(Ph2/2)*(epsr*cos(-freq*t+kx*x+ky*y)+epsi*sin(-freq*t+kx*x+ky*y));
    
	res(1) += sqrt(Ph1/2)*(epsr*sin(freq*t+kx*x+ky*y)+epsi*cos(freq*t+kx*x+ky*y));
	res(1) += sqrt(Ph2/2)*(epsr*sin(-freq*t+kx*x+ky*y)-epsi*cos(-freq*t+kx*x+ky*y));
	cour = cour->next;
      }
      complex<double> res2(res(0),res(1));
      Hcomplex(x,y)=res2;
    }
  }

  //ifft on first dimension
  for (int i = 0 ; i < Hcomplex.sizex() ; i++) {
    DvectorComplex vec(Hcomplex.sizey());
    for (int j = 0 ; j < Hcomplex.sizey() ; j++) {
      vec(j)=Hcomplex(i,j); 
    }
    Ftransform::ifft(vec);
    for (int j = 0 ; j < Hcomplex.sizey() ; j++) {
     Hcomplex(i,j)=vec(j); 
    }
  }

  //ifft on second dimension
  for (int j = 0 ; j < Hcomplex.sizey() ; j++) {
    DvectorComplex vec(Hcomplex.sizex());
    for (int i = 0 ; i < Hcomplex.sizex() ; i++) {
      vec(i)=Hcomplex(i,j); 
    }
    Ftransform::ifft(vec);
    for (int i = 0 ; i < Hcomplex.sizey() ; i++) {
     Hcomplex(i,j)=vec(i); 
    }
  }

  for (int i = 0 ; i < Hcomplex.sizex() ; i++) {
    for (int j = 0 ; j < Hcomplex.sizey() ; j++) {
      (*H)(i,j)=real(Hcomplex(i,j));
    }
  }

}
