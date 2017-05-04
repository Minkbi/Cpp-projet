#include "PhilipsWaveModel.h"
#include <cmath>

PhilipsWaveModel::~PhilipsWaveModel(){
}

PhilipsWaveModel::PhilipsWaveModel(Dvector d, double ali, double i, double aju) : WaveModel(d, ali, i, aju)
{}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &w) : WaveModel(w) {}

complex<double> PhilipsWaveModel::calc(double kx, double ky, double t) const {
  double k = sqrt(kx*kx+ky*ky);
  double ampl = ajustement;
  Dvector dir = direction;
  double freq = 10;
  double epsr = RANDN;
  double epsi = RANDN;
  double L = dir(0)*dir(0)+dir(1)*dir(1)/10;
  double Ph1 = ampl*exp(-1/(k*L)/(k*L))*(kx*dir(0)+ky*dir(1))*(kx*dir(0)+ky*dir(1))/(k*k);
  double Ph2 = ampl*exp(-1/(k*L)/(k*L))*(-kx*dir(0)-ky*dir(1))*(-kx*dir(0)-ky*dir(1))/(k*k);
    
  double res1 = sqrt(Ph1/2)*(epsr*cos(freq*t)-epsi*sin(freq*t));
  res1 += sqrt(Ph2/2)*(epsr*cos(-freq*t)+epsi*sin(-freq*t));
    
  double res2 = sqrt(Ph1/2)*(epsr*sin(freq*t)+epsi*cos(freq*t));
  res2 += sqrt(Ph2/2)*(epsr*sin(-freq*t)-epsi*cos(-freq*t));

  complex<double> res(res1,res2);
  return  res;
}

void PhilipsWaveModel::compute(double t, Height *H) const {
  HeightComplex Hcomplex(*H);
  HeightComplex Hcomplex2(*H);
  int nx = Hcomplex.sizex();
  int ny = Hcomplex.sizey();
  double lx = Hcomplex.taillex();
  double ly = Hcomplex.tailley();

  for (int i = -nx/2 ; i < nx/2 ; i++) {
    for (int j = -ny/2 ; j < ny/2 ; j++) {
      double kx = TWOPI*i/lx;
      double ky = TWOPI*j/ly;
      complex<double> temp(calc(kx,ky,t));
      Hcomplex2(i+nx/2,j+ny/2) = temp;
    }
  }

  printf("%f",imag(Hcomplex2(1,1)));

  for (int x = 0 ; x < nx ; x++) {
    for (int y = 0 ; y < ny ; y++) {
      Hcomplex(x,y) = 0;
      for (int i = -nx/2 ; i < nx/2 ; i++) {
	for (int j = -ny/2 ; j < ny/2 ; j++) {
	  double kx = TWOPI*i/lx;
	  double ky = TWOPI*j/ly;
	  double temp1 = (kx*x*lx/nx)+(ky*y*ly/ny);
	  complex<double> temp(cos(temp1),sin(temp1));
	  Hcomplex(x,y) += Hcomplex2(i+nx/2,j+ny/2) * temp;
	}
      }
    }
  }
  /*
  //ifft on first dimension
  for (int i = 0 ; i < nx ; i++) {
    DvectorComplex vec(ny);
    for (int j = 0 ; j < ny ; j++) {
      vec(j)=Hcomplex(i,j); 
    }
    Ftransform::ifft(vec);
    for (int j = 0 ; j < ny ; j++) {
      Hcomplex(i,j)=vec(j); 
    }
  }

  //ifft on second dimension
  for (int j = 0 ; j < ny ; j++) {
    DvectorComplex vec(nx);
    for (int i = 0 ; i < nx ; i++) {
      vec(i)=Hcomplex(i,j); 
    }
    Ftransform::ifft(vec);
    for (int i = 0 ; i < ny ; i++) {
      Hcomplex(i,j)=vec(i); 
    }
  }*/

  for (int i = 0 ; i < nx ; i++) {
    for (int j = 0 ; j < ny ; j++) {
      (*H)(i,j)=abs(Hcomplex(i,j));
    }
  }

}
