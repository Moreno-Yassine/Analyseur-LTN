#include "../../include/symboles/Ld.h"
#include "../../include/symboles/Variable.h"
#include <map>

Ld::Ld()  : Symbole(I_LD, "I_LD")
{
	nonPresent = false;
}

Ld::~Ld()
{
	for(int i = 0; i<(int)listeDeclarations.size() ;i++)
	{
		delete listeDeclarations[i];
	}
}

bool Ld::setParam(Symbole* s, int place)
{
	listeDeclarations.push_back((Declaration*)s);
	return true;
}

bool Ld::executer()
{
	for(int i=0;i<(int)listeDeclarations.size();i++)
		if(!listeDeclarations[i]->executer())
			return false;
	
	return true;
}

Variable* Ld::trouver(string nomVariable)
{
	map<string, Variable*>::iterator val = listeVariablesNonDeclarees.find(nomVariable);
	if(val!=listeVariablesNonDeclarees.end())
		return val->second;

	for(int i=0;i<(int)listeDeclarations.size();i++)
	{
		if(listeDeclarations[i]->trouver(nomVariable)!=NULL)
		{
			//cout << "End Ld::trouver " << endl;
			return listeDeclarations[i]->trouver(nomVariable);
		}
	}

	return NULL;
}

bool Ld::ajouterVariableNonDeclaree(Variable* var)
{
	pair<map<string,Variable*>::iterator,bool> retour;
	retour = listeVariablesNonDeclarees.insert(pair<string,Variable*>(var->getNom(),var));
	if(retour.second)
		return true;
	else
		return false;
}

bool Ld::display()
{
	//cout << "--------Begin Ld::display()" << endl;
	//cout << "--------Ld::display()::listeDeclarations size : " << (int)listeDeclarations.size() << endl;
	for(int i=0;i<(int)listeDeclarations.size();i++)
		cout << listeDeclarations[i]->print();

	cout << endl;
	return true;
}

bool Ld::checkDoublons()
{
	/*int found = 0;

	for(int i=0;i<(int)listeDeclarations.size();i++)
	{
		if(listeDeclarations[i]->trouver(listeDeclarations[i])!=NULL)
		{
			//cout << "End Ld::trouver " << endl;
			return listeDeclarations[i]->trouver(nomVariable);
		}
	}*/

	return false;
}

vector<Variable*> Ld::getVariables()
{

	vector<Variable*> variables;
	for(int i=0; i<(int)listeDeclarations.size(); i++)
	{
		vector<Variable*> temp = listeDeclarations[i]->getVariables();

		for(int j=0; j<temp.size(); j++)
		{
			variables.push_back(temp[j]);
		}
	}

	for(int i=0;i<(int)variables.size();i++)
	{
		cout << variables[i]->print() << endl;
	}

	return variables;
}