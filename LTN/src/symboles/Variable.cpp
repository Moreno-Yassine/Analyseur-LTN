#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"

#include <iostream>

Variable::Variable(): E(I_ID, "I_ID")
{

}

Variable::Variable(string mot): E(I_ID, "I_ID")
{
	nom = mot;
}

Variable::~Variable()
{
	
}

string Variable::print()
{
	return nom;
}

double Variable::eval()
{
	//cout << "Valeurs size : " << listeValeurs.size() << endl;
	//cout << "Value name : " << nom << endl;
	if(listeValeurs.size()>0)
		return listeValeurs.back().second->eval();
	else
		return 0;
}

bool Variable::setParam(Symbole* symbole, int place)
{
	return true;
}

void Variable::vider()
{
	for(int i=0;i<(int)listeValeurs.size();i++)
		delete listeValeurs[i].second;
	listeValeurs.clear();
}

bool Variable::affecter(Valeur* valeur,Symbole* lieuAffectation)
{
	//cout << "Value name : " << nom << endl;
	//cout << "Value value mmm :" << valeur->eval() << endl;
	listeValeurs.push_back(pair<Symbole*,Valeur*>(lieuAffectation,valeur));
	return true;
}


