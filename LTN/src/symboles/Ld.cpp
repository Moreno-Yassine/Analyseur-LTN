#include "../../include/symboles/Ld.h"
#include "../../include/symboles/Variable.h"
#include <map>

Ld::Ld()  : Symbole(I_LD, "I_LD")
{

}

Ld::~Ld()
{
	for(int i = 0; i<listeDeclarations.size() ;i++)
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
	for(int i=0;i<listeDeclarations.size();i++)
		if(!listeDeclarations[i]->executer())
			return false;
	
	return true;
}

Variable* Ld::trouver(string nomVariable)
{
	for(int i=0;i<listeDeclarations.size();i++)
		if(listeDeclarations[i]->trouver(nomVariable)!=NULL)
			return listeDeclarations[i]->trouver(nomVariable);
	return NULL;
}