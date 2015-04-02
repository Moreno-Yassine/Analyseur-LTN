#include "../../include/symboles/EMult.h"
#include "../../include/symboles/Symbole.h"
#include "../../include/symboles/OpM.h"

EMult::EMult()
{
	exprGauche = NULL;
	exprDroite = NULL;
	operateurMult = NULL;
}

EMult::~EMult()
{

}

double EMult::eval()
{
	double valGauche = exprGauche->eval();
	double valDroite = exprDroite->eval();
	switch(operateurMult->getOperateur()->getIdSymbole())
	{
	case I_mul:
		return valGauche*valDroite;
		break;
	case I_div:
		return valGauche/valDroite;
		break;
	default:
		return 0;
		break;
	}

}

bool EMult::checkVarPasAffectees()
{
	if(exprGauche->checkVarPasAffectees())
	{
		return true;
	}
	if(exprDroite->checkVarPasAffectees())
	{
		return true;
	}

	return false;
}

string EMult::print()
{
	string valeur(exprGauche->print());
	valeur.append(" ");
	valeur.append(operateurMult->print());
	valeur.append(" ");
	valeur.append(exprDroite->print());
	return valeur;
}


bool EMult::setParam(Symbole* symbole, int noPlace)
{
	switch(noPlace)
	{
	case 1:
		exprGauche = (E*)symbole;
		break;
	case 2:
		operateurMult = (opM*)symbole;
		break;
	case 3:
		exprDroite = (E*)symbole;
		break;
	default:
		return false;
		break;
	}
	
	return true;
}


