#include "Symbole.h"

Symbole::Symbole()
{
	symbolesContenus = new vector<Symbole*>();
}

Symbole::Symbole(IdSymbole id)
{
	idSym = id;
}

void Symbole::ajoutSymbole(Symbole* symbole)
{
	symbolesContenus->push_back(symbole);
}

IdSymbole Symbole::getIdSymbole()
{
	return idSym;
}

Symbole::~Symbole()
{

}