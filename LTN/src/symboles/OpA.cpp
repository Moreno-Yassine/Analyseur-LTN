#include "../../include/symboles/OpA.h"

string opA::print()
{
	switch(operateur->getIdSymbole())
	{
	case I_pls:
		return "+";
		break;
	case I_mns:
		return "-";
		break;
	default:
		return "%ERROR%";
		break;
	}
}

bool opA::setParam(Symbole* symbole, int noPlace)
{
	operateur = symbole;
}