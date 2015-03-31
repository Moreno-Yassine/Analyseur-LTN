#include "../../include/symboles/EPlus.h"
#include "../../include/symboles/Symbole.h"
#include "../../include/symboles/OpA.h"

EPlus::EPlus()
{
	exprGauche = NULL;
	exprDroite = NULL;
	operateurArithm = NULL;
}

EPlus::~EPlus()
{

}

double EPlus::eval()
{
	double valGauche = exprGauche->eval();
	double valDroite = exprDroite->eval();
	switch(operateurArithm->getOperateur()->getIdSymbole())
	{
	case I_pls:
		return valGauche+valDroite;
		break;
	case I_mns:
		return valGauche-valDroite;
		break;
	default:
		return 0;
		break;
	}

}

bool EPlus::checkVarPasAffectees()
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

string EPlus::print()
{
	string valeur(exprGauche->print());
	valeur.append(" ");
	valeur.append(operateurArithm->print());
	valeur.append(" ");
	valeur.append(exprDroite->print());
	return valeur;
}


bool EPlus::setParam(Symbole* symbole, int noPlace)
{
	switch(noPlace)
	{
	case 1:
		exprGauche = (E*)symbole;
		break;
	case 2:
		operateurArithm = (opA*)symbole;
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
