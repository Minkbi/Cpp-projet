#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <exception>
#include <iostream>
using namespace std;

class Error : public exception {
 public:
  Error() throw();
  Error(std::string) throw();
  virtual const char* what() const throw();
  virtual ~Error() throw();
 
 private:
  std::string m_phrase;
};
#endif
