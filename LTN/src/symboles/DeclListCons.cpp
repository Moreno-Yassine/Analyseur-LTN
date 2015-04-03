#include "../../include/symboles/DeclListCons.h"
#include "../../include/symboles/Declaration.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"
#include "../../include/symboles/Idc.h"

#include <sstream>


DeclListCons::DeclListCons()
{

}

DeclListCons::~DeclListCons()
{
	for(int i=0; i<(int)listeConstDeclareesIci.size(); i++)
		delete listeConstDeclareesIci[i];
}

bool DeclListCons::executer()
{
	for(int i=0; i<(int)listeConstDeclareesIci.size(); i++)
		listeConstDeclareesIci[i]->executer();
	return true;
}

bool DeclListCons::setParam(Symbole* symbole, int noPlace)
{
	listeConstDeclareesIci.push_back((Idc*)symbole);

	return true;
}

Variable* DeclListCons::trouver(string nomVariable)
{
	for(int i=0; i<(int)listeConstDeclareesIci.size(); i++)
	{
		if(listeConstDeclareesIci[i]->trouver(nomVariable)!=NULL)
		{
			return listeConstDeclareesIci[i]->trouver(nomVariable);
		}
	}
	return NULL;
}

string DeclListCons::print()
{
	stringstream valeur;
	for(int i=0; i<(int)listeConstDeclareesIci.size(); i++)
	{
		valeur<<listeConstDeclareesIci[i]->print();
	}

	return valeur.str(); 
}

vector<Variable*> DeclListCons::getVariables()
{
	vector<Variable*> variables;

	return variables;
}
