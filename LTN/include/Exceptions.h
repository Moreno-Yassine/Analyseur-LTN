#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>
using namespace std;

class Exception_One : public ::exception
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

class Exception_Three : public exception
{
  virtual const char* what() const throw()
  {
    return "Illegal argument exception";
  }
} IllegalArgException;

class Exception_Four : public exception
{
  virtual const char* what() const throw()
  {
    return "Bad File";
  }
} BadFileException;

class Exception_Five : public exception
{
  virtual const char* what() const throw()
  {
    return "Erreur Regex Dictionnaire";
  }
} DictionnaryException;

class Exception_Six : public exception
{
  virtual const char* what() const throw()
  {
    return "Erreur Symbole Inattendu - Le programme ne peut pas continuer \n\n##################\n";
  }
} SymboleSuivantNonConformeException;

class Exception_Seven : public exception
{
  virtual const char* what() const throw()
  {
    return "Erreur Symbole Pas Déclaré - Le programme ne peut pas continuer \n\n##################\n";
  }
} SymbolePasDeclaree;


#endif // EXCEPTIONS_H
