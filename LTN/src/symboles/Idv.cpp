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
	listeVariables.push_back((Variable*)symbole);
	return true;
}
