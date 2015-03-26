#include "../../include/symboles/EMult.h"
#include "../../include/symboles/Symbole.h"

EMult::EMult()
{
	exprGauche = new E();
	exprDroite = new E();
}

EMult::~EMult()
{

}

double EMult::eval()
{
	
	return true;
}

string EMult::print()
{

}


bool EMult::setParam(Symbole* symbole, int noPlace)
{
	return true;
}


