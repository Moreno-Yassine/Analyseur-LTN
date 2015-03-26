#include "../../include/symboles/Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur(): Symbole(I_NB, "I_NB")
{
}

Valeur::Valeur(string valeurP): Symbole(I_NB, "I_NB")
{
	valeur = stoi(valeurP);
}


double Valeur::eval()
{
	return this->valeur;
}

Valeur::~Valeur()
{
	
}
