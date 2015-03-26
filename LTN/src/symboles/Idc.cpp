#include "../../include/symboles/Idc.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"

Idc::Idc() : Symbole(I_Idc, "I_Idc")
{
	variable = NULL;
	valeur = NULL;
}

Idc::~Idc()
{
	variable->vider();
	delete variable;
}


bool Idc::executer()
{
	variable->affecter(valeur,this);
	return true;
}
		
Variable* Idc::getVariable()
{
	return variable;
}

Valeur* Idc::getValeur()
{
	return valeur;
}
		
bool Idc::setParam(Symbole* symbole, int noPlace)
{
	switch(noPlace)
	{
		case 1:
			//Le premier element lu est l'id
			if(variable != NULL)
			{
				variable = (Variable*)symbole;
				//RAISE EXCEPTION
				return false;
			}
			variable = (Variable*)symbole;
			break;
		case 2:
			//Le second element lu est la valeur
			if(valeur != NULL)
			{
				valeur = (Valeur*)symbole;
				//RAISE EXCEPTION
				return false;
			}
			valeur = (Valeur*)symbole;
			break;
		default:
			return false;
			break;
	}
	
	return true;
}