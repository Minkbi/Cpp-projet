#include "Ftransform.h"
#include "Dvector.h"
#include "DvectorComplex.h"

namespace Ftransform {

  DvectorComplex fft(DvectorComplex x){
    int n = x.size();
    if (n>1){
      DvectorComplex even(n/2);
      DvectorComplex odd(n/2-1);
      for (int i = 0 ; i<n/2 ; i++){
	even(i)= x(i*2);
      }
      for (int i = 0 ; i<n/2-1 ; i++){
	odd(i)= x(i*2+1);
      }

      fft(even);
      fft(odd);

      for (int k = 0 ; k<n/2-1 ; k++){
	complex<double> expVal(0,-TWOPI*k/n);
	complex<double> t = odd(k) * exp(expVal);
	x(k) = even(k) + t;
	x(k+n/2) = even(k) - t;
      }

    }
    return x;
  };

  DvectorComplex ifft(DvectorComplex x){
    int n = x.size();
    if (n>1){
      for (int i = 0 ; i<n ; i++){
	x(i) = conj(x(i));
      }
      fft(x);
      for (int i = 0 ; i<n ; i++){
	x(i) = conj(x(i));
      }
      x/=n;
    }
    return x;
  };

}
