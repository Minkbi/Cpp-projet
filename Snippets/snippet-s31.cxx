class POINT
{
  ...
  public :
    friend void colore(POINT &, COLOR &)
};
class COLOR
{
  ...
  public :
    friend void colore(POINT &, COLOR &)
};

void colore( POINT & p, COLOR & c)
{
  ...
}
