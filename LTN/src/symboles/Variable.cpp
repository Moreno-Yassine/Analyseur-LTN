#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"

Variable::Variable(): Symbole(I_ID, "I_ID")
{

}

Variable::Variable(string mot): Symbole(I_ID, "I_ID")
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
	for(int i=0;i<listeValeurs.size();i++)
		delete listeValeurs[i].second;
	listeValeurs.clear();
}

bool Variable::affecter(Valeur* valeur,Symbole* lieuAffectation)
{
	listeValeurs.push_back(pair<Symbole*,Valeur*>(lieuAffectation,valeur));
	return true;
}