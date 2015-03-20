#include "Symbole.h"

Symbole::Symbole()
{
	symbolesContenus = new vector<Symbole*>();
}

Symbole::Symbole(IdSymbole id, string idStr)
{
	idSym = id;
	stringID = idStr;
}

void Symbole::ajoutSymbole(Symbole* symbole)
{
	symbolesContenus->push_back(symbole);
}

IdSymbole Symbole::getIdSymbole()
{
	return idSym;
}

string Symbole::toString()
{
	return stringID;
}

Symbole::~Symbole()
{

}