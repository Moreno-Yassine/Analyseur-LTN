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
}

Variable* DeclListCons::trouver(string nomVariable)
{
	//cout << "Begin DeclListCons::trouver SIZE : " << (int)listeConstDeclareesIci.size() << endl;
	for(int i=0; i<(int)listeConstDeclareesIci.size(); i++)
	{
		if(listeConstDeclareesIci[i]->trouver(nomVariable)!=NULL)
		{
			//cout << "End DeclListCons::trouver " << endl;
			return listeConstDeclareesIci[i]->trouver(nomVariable);
		}
	}
	//cout << "End DeclListCons::trouver NULL" << endl;
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
