#include "../../include/symboles/Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur(): Symbole(I_NB, "I_NB")
{
}

Valeur::Valeur(string nomP, double valeurP): Symbole(I_NB, "I_NB")
{
	valeur = valeurP;
	nom = nomP;
}

Valeur::~Valeur()
{

}
