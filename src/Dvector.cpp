#include "Dvector.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>

Dvector::Dvector(){
  vector = new double;
  dim = 1;
}

Dvector::Dvector(int n) {
  vector = new double[n];
  dim = n;
}

Dvector::Dvector(int n, double val) {
  vector = new double[n];
  dim = n;
  for(int i = 0; i<n; i++) {
    vector[i] = val;
  }
}

Dvector::Dvector(char *filename){
  std::ifstream fichier(filename);
  if ( !fichier ) throw Error("fichier inexistant");
  std::string ligne;
  int i = 1;
  while(fichier.ignore('\n')) {
    i++;
  }
  dim = i;
  vector = new double[i];
  for (i = 0; i < dim; i++)  {
    getline(fichier, ligne);
    vector[i] = atof(ligne.c_str());
  }
  fichier.close();
}

Dvector::Dvector(const Dvector& v) {
  int n = v.dim;
  vector = new double[n];
  dim = n;
  for(int i = 0; i<n; i++) {
    vector[i] = v.vector[i];
  }
}

Dvector::~Dvector() {
  if (vector != NULL) {
    delete vector;
  }
}

void Dvector::display(std::ostream& str) const {
  for (int i=0; i<dim; i++) {
    str << vector[i] << "\n";
  }
}

int Dvector::size() const {
  return dim;
}

void Dvector::fillRandomly() {
  for (int i=0; i<dim; i++) {
    vector[i] = random();
  }
}

void Dvector::set(int i, double val) {
  if (i*(dim-i-1)<0) {
    throw Error("Wrong indice for vector");
  } else {
    vector[i] = val;
  }
}

double& Dvector::operator()(int i) const {
  if (i*(dim-i-1)<0) {
    throw Error("Wrong indice for vector");
  } else {
    return vector[i];
  }
}

Dvector& Dvector::operator=(Dvector v) {
  if (this != &v) {
    int n = v.size();
    vector = new double[n];
    dim = n;
    for(int i = 0; i<n; i++) {
      vector[i] = v(i);
    }
  }
  return *this;
}

Dvector operator+(const Dvector& v1, const Dvector& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n < m) {
    Dvector newv(m);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) + v2(i));
    }
    for (int i=n; i<m; i++) {
      newv.set(i, v2(i));
    }
    return newv;
  } else {
    Dvector newv(n);
    for (int i=0; i<m; i++) {
      newv.set(i, v1(i) + v2(i));
    }
    for (int i=m; i<n; i++) {
      newv.set(i, v1(i));
    }
    return newv;
  }
}

Dvector operator-(const Dvector& v1, const Dvector& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n < m) {
    Dvector newv(m);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) - v2(i));
    }
    for (int i=n; i<m; i++) {
      newv.set(i, -v2(i));
    }
    return newv;
  } else {
    Dvector newv(n);
    for (int i=0; i<m; i++) {
      newv.set(i, v1(i) - v2(i));
    }
    for (int i=m; i<n; i++) {
      newv.set(i, v1(i));
    }
    return newv;
  }
}

double operator*(const Dvector& v1, const Dvector& v2) {
  int n = v1.size();
  int m = v2.size();
  if (n != m) {
    throw Error("scalaire must be on same size vector");
  } else {
    double val = 0;
    for (int i=0; i<n; i++) {
      val += v1(i) * v2(i);
    }
    return val;
  }
}

Dvector operator+(const Dvector& v1, double val) {
  int n = v1.size();
  Dvector newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) + val);
  }
  return newv;
}

Dvector operator-(const Dvector& v1, double val) {
  int n = v1.size();
  Dvector newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) - val);
  }
  return newv;
}

Dvector operator*(const Dvector& v1, double val) {
  int n = v1.size();
  Dvector newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, v1(i) * val);
  }
  return newv;
}

Dvector operator/(const Dvector& v1, double val) {
  if (val != 0) {
    int n = v1.size();
    Dvector newv(n);
    for (int i=0; i<n; i++) {
      newv.set(i, v1(i) / val);
    }
    return newv;
  } else {
    throw Error("Division pa zero !");
  }
}

void operator+=(Dvector& v1, double val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) + val);
  }
}

void operator-=(Dvector& v1, double val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) - val);
  }
}

void operator*=(Dvector& v1, double val) {
  int n = v1.size();
  for (int i=0; i<n; i++) {
    v1.set(i, v1(i) * val);
  }
}

void operator/=(Dvector& v1, double val) {
  if (val != 0) {
    int n = v1.size();
    for (int i=0; i<n; i++) {
      v1.set(i, v1(i) / val);
    }
  } else {
    throw Error("Divided by zero");
  }
}

void operator+=(Dvector& v1, const Dvector& v2) {
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

void operator-=(Dvector& v1, const Dvector& v2) {
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

Dvector operator-(const Dvector& v1) {
  int n = v1.size();
  Dvector newv(n);
  for (int i=0; i<n; i++) {
    newv.set(i, -v1(i));
  }
  return newv;
}

std::ostream& operator<<(std::ostream& os, const Dvector& v) {
  int n = v.size();
  for (int i=0; i<n; i++) {
    os << v(i) << "\n";
  }
  return os;
}

std::istream& operator>>(std::istream& is, Dvector& obj) {
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

bool operator==(const Dvector& v1, const Dvector& v2) {
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
