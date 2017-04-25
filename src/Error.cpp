#include "Error.h"

Error::Error() throw()
{m_phrase = "";}

Error::Error(std::string phrase) throw()
{m_phrase = phrase;}

const char* Error::what() const throw()
{
  return m_phrase.c_str();
}

Error::~Error() throw()
{}
