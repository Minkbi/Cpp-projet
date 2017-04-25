class POINT
{
  protected :
    int dim; double *pCor;
  public :
    POINT(int d, double v=0);
    POINT(const POINT &P);
    POINT & operator =
      (const POINT &);
};
