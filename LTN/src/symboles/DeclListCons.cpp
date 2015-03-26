#include "../../include/symboles/DeclListCons.h"
#include "../../include/symboles/Declaration.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Idc.h"


DeclListCons::DeclListCons()
{

}

DeclListCons::~DeclListCons()
{
	for(int i=0; i<listeConstDeclareesIci.size(); i++)
		delete listeConstDeclareesIci[i];
}

bool DeclListCons::executer()
{
	for(int i=0; i<listeConstDeclareesIci.size(); i++)
		listeConstDeclareesIci[i]->executer();
	return true;
}

bool DeclListCons::setParam(Symbole* symbole, int noPlace)
{
	listeConstDeclareesIci.push_back((Idc*)symbole);
}

Variable* DeclListCons::trouver(string nomConstiable)
{
	for(int i=0; i<listeConstDeclareesIci.size(); i++)
		if(listeConstDeclareesIci[i]->getVariable()->getNom() == nomConstiable)
			return listeConstDeclareesIci[i]->getVariable();
	return NULL;
}

