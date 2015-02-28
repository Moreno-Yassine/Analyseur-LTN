#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
using namespace std;

class Exception_One : public exception
{
  virtual const char* what() const throw()
  {
    return "You have reached the maximum number of allowed arguments";
  }
} MaxArgsException;

class Exception_Two : public exception
{
  virtual const char* what() const throw()
  {
    return "Not enough arguments";
  }
} MinArgsException;


#endif // EXCEPTIONS_H
