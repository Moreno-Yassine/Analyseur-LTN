#include "../../include/symboles/DeclListVar.h"
#include "../../include/symboles/Declaration.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Idv.h"

DeclListVar::DeclListVar()
{

}

DeclListVar::~DeclListVar()
{
	for(int i=0; i<listeVarDeclareesIci.size(); i++)
		delete listeVarDeclareesIci[i];
}

bool DeclListVar::executer()
{
	for(int i=0; i<listeVarDeclareesIci.size(); i++)
		listeVarDeclareesIci[i]->executer();
	return true;
}

bool DeclListVar::setParam(Symbole* symbole, int noPlace)
{
	listeVarDeclareesIci.push_back((Idv*)symbole);
}

Variable* DeclListVar::trouver(string nomVariable)
{
	for(int i=0; i<listeVarDeclareesIci.size(); i++)
		if(listeVarDeclareesIci[i]->getVariable()->getNom() == nomVariable)
			return listeVarDeclareesIci[i]->getVariable();
	return NULL;
}