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
	for(int i=0; i<(int)listeConstantes.size(); i++)
	{
		listeConstantes[i]->affecter(listeValeurs[i],this);

		//cout << "Variable : " << listeVariables[i]->getNom() << ". Value : " << listeValeurs[i]->eval();
	}
	//variable->affecter(valeur,this);
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

string  Idc::print()
{
	stringstream resultat;
	for(int i=0; i<(int)listeConstantes.size(); i++)
	{	
		resultat<<"const ";
		resultat<<listeConstantes[i]->getNom();
		resultat<<" = ";
		resultat<<listeValeurs[i]->eval();
		resultat<<";"<<endl;
	}
	
	return resultat.str(); 
}

Variable* Idc::trouver(string nomVariable)
{
	//cout << "Begin Idc::trouver SIZE : " << (int)listeConstantes.size() << endl;
	for(int i=0; i<(int)listeConstantes.size(); i++)
	{
		//cout << "Idc::trouver nomVariable :" << listeConstantes[i]->print() << endl;
		if(listeConstantes[i]->print() == nomVariable)
			return listeConstantes[i];
	}
	return NULL;
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
				variable->setConst();
				listeConstantes.push_back(variable);

				//RAISE EXCEPTION
				return false;
			}
			
			variable = (Variable*)symbole;
			variable->setConst();
			listeConstantes.push_back((Variable*)variable);
			break;
		case 2:
			//Le second element lu est la valeur
			if(valeur != NULL)
			{
				valeur = (Valeur*)symbole;
				listeValeurs.push_back((Valeur*)symbole);
				//RAISE EXCEPTION
				return false;
			}
			listeValeurs.push_back((Valeur*)symbole);
			valeur = (Valeur*)symbole;
			break;
		default:
			return false;
			break;
	}
	
	return true;
}
