#include "../../include/symboles/E.h"

E::E() : Symbole(I_E, "I_E")
{

}

E::E(IdSymbole id, string idStr) : Symbole(I_E, "I_E")
{
	idSym = id;
	stringID = idStr;
}

E::~E()
{

}

double E::eval()
{
}

string E::print()
{
}

bool E::checkVarPasAffectees()
{
}

void E::setId(IdSymbole idSymP, string stringIDP)
{
	idSym = idSymP;
	stringID = stringIDP;
}

bool E::setParam(Symbole* symbole, int placeSymbole)
{
	return true;
}
