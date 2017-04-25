class POINT_COLOR:public POINT
{
  protected :
    int colour;
  public :
    POINT_COLOR
      (const POINT_COLOR &P);
    POINT_COLOR & operator =
      (const POINT_COLOR &);
};
