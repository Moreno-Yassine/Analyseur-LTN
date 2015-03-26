#include "../../include/symboles/EBin.h"
#include "../../include/symboles/Symbole.h"

EBin::EBin()
{
	exprGauche = new E();
	exprDroite = new E();
}

EBin::~EBin()
{

}

string EBin::print()
{

}

double EBin::eval()
{
	
}


bool EBin::setParam(Symbole* symbole, int noPlace)
{
	return true;
}



