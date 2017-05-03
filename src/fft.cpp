#include "fft.h"
#include "Dvector.h"
#include "DvectorComplex.h"

namespace fft {
  /*fft() {
  }
  ifft() {
    
  }
fft(DvectorComplex *x){
	int n = x.size();
	if (n>1){
		DvectorComplex *even = NULL;
		DvectorComplex *odd = NULL;
		for (int i = 0 , i<n/2, i++){
			even[i]= x[i*2];
		}
		for (int i = 0 , i<n/2-1, i++){
			odd[i]= x[i*2+1];
		}
		ftt(even);
		ftt(odd);

		for (int k=0 , k<N/2-1,k++){
			complex<double> expVal = -TWOPI*i*k/n;
			complex<double> t = odd[k] * exp(expVal);
			x[k] = even[k] + t;
			x[k+n/2] = even[k] - t;
		}

	}
	return x;
};

ifft(DvectorComplex *x){
	int n = x.sie();
	if (n>1){

	}
};
*/
};
