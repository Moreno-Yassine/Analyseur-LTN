#include "../../include/symboles/Programme.h"

Programme::Programme() : Symbole(I_P, "I_P")
{

}

Programme::~Programme()
{
}

bool Programme::setParam(Symbole* symbole, int placeSymbole)
{
	if(placeSymbole==1)
		ptLd = (Ld*)symbole;
	else if(placeSymbole==2)
		ptLi = (Li*)symbole;
	else
		return false;

	return true;
}

bool Programme::executer()
{
	//cout << "--------Begin Programme::execute()" << endl;
	if(!ptLd->executer())
		return false;
	if(!ptLi->executer())
		return false;
	return true;
}

bool Programme::display()
{
	//cout << "--------Begin Programme::display()" << endl;
	if(ptLd==NULL)
		cout << "Attention : AUCUNE DECLARATION" << endl;

	if(ptLi==NULL)
		cout << "Attention : AUCUNE INSTRUCTION" << endl;

	if(!ptLd->display())
		return false;
	if(!ptLi->display())
		return false;
	return true;
}

bool Programme::checkModifiedConst()
{
	if(ptLi!=NULL)
	{
		return ptLi->checkModifiedConst();
	}

	return false;
}

bool Programme::checkVarPasAffectees()
{
	vector<Variable*> variables = ptLd->getVariables();

	if(ptLi!=NULL)
	{
		return ptLi->checkVarPasAffectees();
	}

	return false;
}

bool Programme::checkDoublons()
{
	if(ptLd!=NULL)
	{
		return ptLd->checkDoublons();
	}

	return false;
}
