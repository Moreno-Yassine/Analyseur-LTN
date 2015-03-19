#include "Valeur.h"
#include <iostream>
#include <string> 

Valeur::Valeur()
{
	nombre = 0;
}

Valeur::Valeur(string mot)
{
	nombre = stoi(mot);
}

Valeur::~Valeur()
{

}
