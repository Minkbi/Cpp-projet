#include "PhilipsWaveModel.h"
#include <cmath>

PhilipsWaveModel::~PhilipsWaveModel(){
}

PhilipsWaveModel::PhilipsWaveModel(Dvector d, double ali, double i, double aju, int nx, int ny) : WaveModel(d, ali, i, aju)
{
  epr = new double*[nx];
  epi = new double*[ny];
  for (int i=0; i<nx; i++) {
    epr[i] = new double[nx];
    epi[i] = new double[ny];
    for (int j=0; j<ny; j++) {
      epr[i][j] = RANDN;
      epi[i][j] = RANDN;
    }
  } 
}

PhilipsWaveModel::PhilipsWaveModel(const PhilipsWaveModel &w) : WaveModel(w) {}

complex<double> PhilipsWaveModel::calc(double kx, double ky, double t, int i, int j) const {
  double k2 = kx*kx+ky*ky;
  double ampl = ajustement;
  Dvector dir = direction;
  double freq = sqrt(sqrt(k2)*100);
  double epsr = epr[i][j];
  double epsi = epi[i][j];
  double L = intensite*100;
  double exptemp = ampl*exp(-1/(k2*(L*L)))/k2;
  double Ph1 = exptemp*(kx*dir(0)+ky*dir(1))*(kx*dir(0)+ky*dir(1));
  double Ph2 = exptemp*(-kx*dir(0)-ky*dir(1))*(-kx*dir(0)-ky*dir(1));
  double res1 = sqrt(Ph1/2)*(epsr*cos(freq*t)-epsi*sin(freq*t));
  res1 += sqrt(Ph2/2)*(epsr*cos(-freq*t)+epsi*sin(-freq*t));
    
  double res2 = sqrt(Ph1/2)*(epsr*sin(freq*t)+epsi*cos(freq*t));
  res2 += sqrt(Ph2/2)*(epsr*sin(-freq*t)-epsi*cos(-freq*t));
  complex<double> res(res1,res2);
  return  res;
}

void PhilipsWaveModel::compute(double t, Height *H) const {
  HeightComplex Hcomplex(*H);
  int nx = Hcomplex.sizex();
  int ny = Hcomplex.sizey();
  double lx = Hcomplex.taillex();
  double ly = Hcomplex.tailley();
  for (int i = -nx/2 ; i < nx/2 ; i++) {
    for (int j = -ny/2 ; j < ny/2 ; j++) {
      if (i!=0&&j!=0) {
	double kx = TWOPI*i/lx;
	double ky = TWOPI*j/ly;
	complex<double> temp1(calc(kx,ky,t,i+nx/2,j+ny/2));
	double temp2 = (kx*i*lx/nx)+(ky*j*ly/ny);
	complex<double> temp3(cos(temp2),sin(temp2));
	Hcomplex(i+nx/2,j+ny/2) = temp1 * temp3;
      } else {
	Hcomplex(i+nx/2,j+ny/2) = 0;
      }
    }
  }

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
  }

  for (int i = 0 ; i < nx ; i++) {
    for (int j = 0 ; j < ny ; j++) {
      (*H)(i,j)=abs(Hcomplex(i,j));
    }
  }

}
