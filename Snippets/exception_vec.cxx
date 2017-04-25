#include <exception>

class POINT{
  public:

  class Erreur : public std::exception {
    public:
      virtual const char * what(void) const throw () {
        return "Erreur generique sur les points";
      }
  };
  class ErreurAllocation : public std::exception {
    public:
      virtual const char * what(void) const throw () {
        return "Erreur d'allocation mémoire";
      }
  };
  class ErreurAcces : public std::exception {
    public:
      virtual const char * what(void) const throw () {
        return "Erreur d'acces au données du vecteur";
      }
  };
};

