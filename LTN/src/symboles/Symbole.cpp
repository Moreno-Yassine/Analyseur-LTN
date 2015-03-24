#include "Symbole.h"
#include <iostream>
using namespace std;

Symbole::Symbole()
{
	symbolesContenus = new vector<Symbole*>();
}

Symbole::Symbole(IdSymbole id, string idStr)
{
	idSym = id;
	stringID = idStr;
	symbolesContenus = new vector<Symbole*>();
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

void Symbole::setId(IdSymbole idSymP, string stringIDP)
{
	idSym = idSymP;
	stringID = stringIDP;
}

bool Symbole::setParam(Symbole* symbole, int place)
{
	cout<<"SET PARAM par defaut"<<endl;
	return false;
}

Symbole::~Symbole()
{

}