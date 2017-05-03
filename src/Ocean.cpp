#include "Ocean.h"

Ocean::Ocean(double plx,double ply,int pnx,int pny,WaveModelPtr pmodel,Height pH) :
  lx(plx),
  ly(ply),
  nx(pnx),
  ny(pny),
  model(pmodel),
  H(pH)
{
  t = 0;
}

Ocean::~Ocean(){}

int Ocean::getNx() const{
  return nx;
}

int Ocean::getNy() const {
  return ny;
}

double Ocean::get_lx() const {
  return lx;
}

double Ocean::get_ly() const {
  return ly;
}

void Ocean::main_computation() {
  (*model).compute(t,&H);
  t += 0.001;
}

/** Initialise la grille dans la direction x
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x]   = (lx/nx)*x;
    vertices[3*x+2] = (ly/ny)*y;
  }
  vertices[3*nx]   = lx;
  vertices[3*nx+2] = (ly/ny)*y;
}

/** Initialise la grille dans la direction y
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les coordonnées des noeuds
 */
void Ocean::init_gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y]   = (lx/nx)*x;
    vertices[3*y+2] = (ly/ny)*y;
  }
  vertices[3*ny]   = (lx/nx)*x;
  vertices[3*ny+2] = ly;
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un y donné
 *  param[in]   y        abscisse de la colonne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayX(const int y, double* const vertices) const {
  for(int x=0 ; x<nx ; x++) {
    vertices[3*x+1] = 1-2*((x+y)%2)*H(y,x);
  }
  vertices[3*nx+1] = 1-2*((nx+y)%2)*H(y,0);
}

/** Convertit le champs de hauteur en tabeau directement utilisable
 *  par OpenGL pour un x donné
 *  param[in]   x        abscisse de la ligne à parcourir
 *  param[out]  vertices buffer contenant les valeurs aux noeuds
 */
void Ocean::gl_VertexArrayY(const int x, double* const vertices) const {
  for(int y=0 ; y<ny ; y++) {
    vertices[3*y+1] = H(y,x);
  }
  vertices[3*ny+1]  = H(0,x);
}

