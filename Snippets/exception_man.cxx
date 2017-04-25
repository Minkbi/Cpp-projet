try
{
  // Code à tester
}
catch (POINT::ErreurAcces &e)
{
  cerr << e.what() << endl;
  // Traitement specifique a cette erreur
}
catch (POINT::ErreurAllocation &e)
{
  cerr << e.what() << endl;
  // Traitement specifique a cette erreur
}
