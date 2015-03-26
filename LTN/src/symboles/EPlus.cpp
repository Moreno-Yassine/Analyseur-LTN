#include "../../include/symboles/EPlus.h"
#include "../../include/symboles/Symbole.h"
#include "../../include/symboles/OpA.h"

EPlus::EPlus()
{
	exprGauche = new E();
	exprDroite = new E();
	operateurArithm = new opA();
}

EPlus::~EPlus()
{

}

double EPlus::eval()
{

}

string EPlus::print()
{

}


bool EPlus::setParam(Symbole* symbole, int noPlace)
{
	return true;
}
