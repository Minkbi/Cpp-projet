class POINT
{ virtual void afficher() = 0;};
class POINT_COLOR: public POINT
{ virtual void afficher()
  {std::cout << "(x,y) = ( " << x << " ," << y << " )"<<std::endl;
    std::cout<< "c= " << c <<std::endl}};
class POINT_RGB: public POINT
{ virtual void afficher()
  {std::cout << "(x,y) = ( " << x << " ," << y << " )"<<std::endl;
    std::cout<< "RGB = (" << r << " , "<< g <<" , "<<b<< " )
      << std::endl}};
