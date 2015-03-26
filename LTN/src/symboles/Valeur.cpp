#include "../../include/symboles/Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur(): Symbole(I_NB, "I_NB")
{
}

Valeur::Valeur(string nomP): Symbole(I_NB, "I_NB")
{
	nom = nomP;
}

Valeur::Valeur(string nomP, double valeurP): Symbole(I_NB, "I_NB")
{
	valeur = valeurP;
	nom = nomP;
}

double Valeur::eval()
{
	return true;
}

Valeur::~Valeur()
{
	
}
