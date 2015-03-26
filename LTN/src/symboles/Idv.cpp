#include "../../include/symboles/Idv.h"
#include "../../include/symboles/Variable.h"


Idv::Idv() : Symbole(I_Idv, "I_Idv")
{
	variable = NULL;
}

Idv::~Idv()
{
	delete variable;
}


bool Idv::executer()
{
	return true;
}
		
Variable* Idv::getVariable()
{
	return variable;
}
		
bool Idv::setParam(Symbole* symbole, int noPlace)
{
	if(variable != NULL)
	{
		variable = (Variable*)symbole;
		//RAISE EXCEPTION
		return false;
	}
	variable = (Variable*)symbole;
	return true;
}