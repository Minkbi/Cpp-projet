int main()
{
  POINT *A = (POINT *) (POINT_COLOR(2));
  POINT *B = (POINT *) (POINT_RGB(2));
  A->afficher(); // appel de POINT_COLOR::afficher();
  B->afficher(); // appel de POINT_RGB::afficher();
}
