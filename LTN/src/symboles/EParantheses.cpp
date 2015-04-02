#include "../../include/symboles/EParantheses.h"
#include "../../include/symboles/Symbole.h"

EParantheses::EParantheses()
{
	expression = NULL;
}

EParantheses::~EParantheses()
{
	delete expression;
}

double EParantheses::eval()
{
	expression->eval();
}

bool EParantheses::checkVarPasAffectees()
{
	if(expression->checkVarPasAffectees())
	{
		return true;
	}

	return false;
}


string EParantheses::print()
{
	string valeurPrint("(");
	valeurPrint.append(expression->print());
	valeurPrint.append(")");
	return valeurPrint;
}


bool EParantheses::setParam(Symbole* symbole, int noPlace)
{
	expression = (E*)symbole;
	return true;
}



