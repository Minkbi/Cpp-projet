POINT::POINT(unsigned int d, double val)
{
  dim=d ;
  if (dim == 0) throw ErreurAllocation();
  pCor=new double[dim];
  for(int i=0;i<dim; i++)
    pCor[i]=val;
}
const double &POINT::operator()(int i) const // par copie
{
  if (i < 0)
    throw ErreurAcces();
  if (i >= dim)
    throw ErreurAcces();
  return pCor[i];
}
