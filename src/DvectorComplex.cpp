#include "DvectorComplex.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

DvectorComplex::DvectorComplex(){
  vector = new std::complex<double>;
  dim = 1;
}

DvectorComplex::DvectorComplex(int n) {
  vector = new complex<double>[n];
  dim = n;
}

DvectorComplex::DvectorComplex(int n, std::complex<double> val) {
  vector = new std::complex<double>[n];
  dim = n;
  for(int i = 0; i<n; i++) {
    vector[i] = val;
  }
}

DvectorComplex::DvectorComplex(const DvectorComplex& v) {
  int n = v.dim;
  vector = new std::complex<double>[n];
  dim = n;
  for(int i = 0; i<n; i++) {
    vector[i] = v.vector[i];
  }
}

DvectorComplex::~DvectorComplex() {
  if (vector != NULL) {
    delete vector;
  }
}

void DvectorComplex::display(std::ostream& str) const {
  for (int i=0; i<dim; i++) {
    str << vector[i] << "\n";
  }
}

int DvectorComplex::size() const {
  return dim;
}
void DvectorComplex::conjVect() {
	for (int i=0; i<dim; i++) {
		vector[i]=conj(vector[i]);
	  }
}

void DvectorComplex::fillRandomly() {
  for (int i=0; i<dim; i++) {
    vector[i] = random();
  }
}

void DvectorComplex::set(int i, complex<double> val) {
  if (i*(dim-i-1)<0) {
    throw Error("Wrong indice for vector");
  } else {
    vector[i] = val;
  }
}

complex<double>& DvectorComplex::operator()(int i) const {
  if (i*(dim-i-1)<0) {
    throw Error("Wrong indice for vector");
  } else {
    return vector[i];
  }
}

DvectorComplex& DvectorComplex::operator=(DvectorComplex v) {
  if (this != &v) {
    int n = v.size();
    vector = new std::complex<double>[n];
    dim = n;
    for(int i = 0; i<n; i++) {
      vector[i] = v(i);
    }
  }
  return *this;
}

DvectorComplex operator+(const DvectorComplex& v1, const DvectorComplex& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n < m) {
    DvectorComplex newv(m);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) + v2(i));
    }
    for (int i=n; i<m; i++) {
      newv.set(i, v2(i));
    }
    return newv;
  } else {
    DvectorComplex newv(n);
    for (int i=0; i<m; i++) {
      newv.set(i, v1(i) + v2(i));
    }
    for (int i=m; i<n; i++) {
      newv.set(i, v1(i));
    }
    return newv;
  }
}

DvectorComplex operator-(const DvectorComplex& v1, const DvectorComplex& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n < m) {
    DvectorComplex newv(m);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) - v2(i));
    }
    for (int i=n; i<m; i++) {
      newv.set(i, -v2(i));
    }
    return newv;
  } else {
    DvectorComplex newv(n);
    for (int i=0; i<m; i++) {
      newv.set(i, v1(i) - v2(i));
    }
    for (int i=m; i<n; i++) {
      newv.set(i, v1(i));
    }
    return newv;
  }
}

complex<double> operator*(const DvectorComplex& v1, const DvectorComplex& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n != m) {
    throw Error("scalaire must be on same size vector");
  } else {
    std::complex<double> val = 0;
    for (int i=0; i<n; i++) {
      val += v1(i) * v2(i);
    }
    return val;
  }
}

DvectorComplex operator+(const DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  DvectorComplex newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) + val);
  }
  return newv;
}

DvectorComplex operator-(const DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  DvectorComplex newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) - val);
  }
  return newv;
}

DvectorComplex operator*(const DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  DvectorComplex newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) * val);
  }
  return newv;
}

DvectorComplex operator/(const DvectorComplex& v1, complex<double> val) {
	complex<double> zero = 0.+ 0.i;
	if (val != zero) {
    int n = v1.size();
    DvectorComplex newv(n);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) / val);
    }
    return newv;
  } else {
    throw Error("Division par zero !");
  }
}

void operator+=(DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) + val);
  }
}

void operator-=(DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) - val);
  }
}

void operator*=(DvectorComplex& v1, complex<double> val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) * val);
  }
}

void operator/=(DvectorComplex& v1, complex<double> val) {
  complex<double> zero = 0.+ 0.i;
  if (val != zero) {
    int n = v1.size();
    for (int i=0; i<n; i++) {
      v1.set(i, v1(i) / val);
    }
  } else {
    throw Error("Divided by zero");
  }
}

void operator+=(DvectorComplex& v1, const DvectorComplex& v2) {
  int n = v1.size();
  int m = v2.size();
  if (m<n) {
    for (int i=0; i<m; i++) {
      v1.set(i, v1(i) + v2(i));
    }
  } else {
    for (int i=0; i<n; i++) {
      v1.set(i, v1(i) + v2(i));
    }
  }
}

void operator-=(DvectorComplex& v1, const DvectorComplex& v2) {
  int n = v1.size();
  int m = v2.size();
  if (m<n) {
    for (int i=0; i<m; i++) {
      v1.set(i, v1(i) - v2(i));
    }
  } else {
    for (int i=0; i<n; i++) {
      v1.set(i, v1(i) - v2(i));
    }
  }
}

DvectorComplex operator-(const DvectorComplex& v1) {
  int n = v1.size();
  DvectorComplex newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, -v1(i));
  }
  return newv;
}

std::ostream& operator<<(std::ostream& os, const DvectorComplex& v) {
  int n = v.size();
  for (int i=0; i<n; i++) {
    os << v(i) << "\n";
  }
  return os;
}

std::istream& operator>>(std::istream& is, DvectorComplex& obj) {
  char c;
  std::string ligne = "";
  bool notend = true;
  int i = 0;
  while (is.get(c) && notend) {
    if (c != '\n' && c != '\0') {
      ligne += c;
    } else if (c != '\0') {
      obj(i) = atof(ligne.c_str());
      ligne = "";
      i++;
    } else {
      notend = false;
    }
  }
  return is;
}

bool operator==(const DvectorComplex& v1, const DvectorComplex& v2) {
  bool egal = true;
  int n = v1.size();
  if (n != v2.size()) {
    egal = false;
  } else {
    for (int i=0; (i<n && egal); i++) {
      if (v1(i) != v2(i)) {
	egal = false;
      }
    }
  }
  return egal;
}
