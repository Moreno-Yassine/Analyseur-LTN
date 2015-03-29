#include "../../include/symboles/OpM.h"

string opM::print()
{
	switch(operateur->getIdSymbole())
	{
	case I_mul:
		return "*";
		break;
	case I_div:
		return "/";
		break;
	default:
		return "%ERROR%";
		break;
	}
}

bool opM::setParam(Symbole* symbole, int noPlace)
{
	operateur = symbole;

	return true;
}