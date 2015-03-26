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


double Valeur::eval()
{
	return this->valeur;
}

Valeur::~Valeur()
{
	
}
