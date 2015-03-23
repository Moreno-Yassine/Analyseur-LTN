#include "Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur(): Symbole(I_NB, "I_NB")
{
	nombre = 0;
}

Valeur::Valeur(string mot): Symbole(I_NB, "I_NB")
{
	nombre = stoi(mot);
}

Valeur::~Valeur()
{

}
