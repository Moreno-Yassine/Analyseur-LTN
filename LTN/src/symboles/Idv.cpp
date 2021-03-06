#include "../../include/symboles/Idv.h"
#include "../../include/symboles/Variable.h"
#include <sstream>
#include <iostream>


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

string  Idv::print()
{
	stringstream resultat;
	for(int i=0; i<(int)listeVariables.size(); i++)
	{	
		resultat<<"var ";
		resultat<<listeVariables[i]->getNom();
		resultat<<";"<<endl;
	}
	
	return resultat.str(); 
}
		
bool Idv::setParam(Symbole* symbole, int noPlace)
{
	if(variable != NULL)
	{
		variable = (Variable*)symbole;
		listeVariables.push_back((Variable*)symbole);
		return false;
	}
	listeVariables.push_back((Variable*)symbole);
	variable = (Variable*)symbole;
	return true;
}

Variable* Idv::trouver(string nomVariable)
{
	for(int i=0; i<(int)listeVariables.size(); i++)
	{
		if(listeVariables[i]->print() == nomVariable)
		{
			return listeVariables[i];
		}
	}

	return NULL;
}

vector<Variable*> Idv::getVariables()
{
	vector<Variable*> variables;

	for(int i=0; i<(int)listeVariables.size(); i++)
	{
		variables.push_back(listeVariables[i]);
	}

	return variables;

}
