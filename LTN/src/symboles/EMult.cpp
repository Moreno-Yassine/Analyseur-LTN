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
	
}

string EMult::print()
{

}


bool EMult::setParam(Symbole* symbole, int noPlace)
{
	return true;
}


