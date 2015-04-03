#include "../../include/symboles/DeclListVar.h"
#include "../../include/symboles/Declaration.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Idv.h"
#include <sstream>

DeclListVar::DeclListVar()
{

}

DeclListVar::~DeclListVar()
{
	for(int i=0; i<(int)listeVarDeclareesIci.size(); i++)
		delete listeVarDeclareesIci[i];
}

bool DeclListVar::executer()
{
	for(int i=0; i<(int)listeVarDeclareesIci.size(); i++)
		listeVarDeclareesIci[i]->executer();
	return true;
}

bool DeclListVar::setParam(Symbole* symbole, int noPlace)
{
	listeVarDeclareesIci.push_back((Idv*)symbole);
}

Variable* DeclListVar::trouver(string nomVariable)
{
	for(int i=0; i<(int)listeVarDeclareesIci.size(); i++)
	{
		if(listeVarDeclareesIci[i]->trouver(nomVariable)!=NULL)
			return listeVarDeclareesIci[i]->trouver(nomVariable);
	}
	return NULL;
}

string DeclListVar::print()
{
	stringstream valeur;
	for(int i=0; i<(int)listeVarDeclareesIci.size(); i++)
	{	
		valeur<<listeVarDeclareesIci[i]->print();
	}

	return valeur.str(); 
}

vector<Variable*> DeclListVar::getVariables()
{
	vector<Variable*> variables;
	for(int i=0; i<(int)listeVarDeclareesIci.size(); i++)
	{
		vector<Variable*> temp = listeVarDeclareesIci[i]->getVariables();

		for(int j=0; j<(int)temp.size(); j++)
		{
			variables.push_back(temp[j]);
		}
	}

	return variables;
}
