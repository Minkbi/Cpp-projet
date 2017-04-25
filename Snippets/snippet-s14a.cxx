#ifndef POINT_COLOR_H
#define POINT_COLOR_H
#include "POINT.h"

class POINT_COLOR :
  public POINT
{
  protected :
    int couleur;
  public :
    void colorer (int c);
};
#endif
