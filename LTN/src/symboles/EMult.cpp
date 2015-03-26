#include "../../include/symboles/EMult.h"
#include "../../include/symboles/Symbole.h"
#include "../../include/symboles/OpM.h"

EMult::EMult()
{
	exprGauche = new E();
	exprDroite = new E();
	operateurMult = new opM();
}

EMult::~EMult()
{

}

double EMult::eval()
{
	//TODO
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


