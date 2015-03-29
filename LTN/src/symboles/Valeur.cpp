#include "../../include/symboles/Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur(): E(I_NB, "I_NB")
{
}

Valeur::Valeur(string valeurP): E(I_NB, "I_NB")
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

bool Valeur::setParam(Symbole* symbole,int noPlace)
{
	valeur = ((Valeur*)symbole)->eval();
	return true;
}

string Valeur::print()
{
	stringstream resultat;
	resultat<<this->valeur;
	return resultat.str();
}
