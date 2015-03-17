#include "Symbole.h"

Symbole::Symbole()
{
	symbolesContenus = new vector<Symbole*>();
}

void Symbole::ajoutSymbole(Symbole* symbole)
{
	symbolesContenus.push_back(symbole);
}


Symbole::~Symbole()
{

}