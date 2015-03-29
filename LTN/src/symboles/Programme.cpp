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
	cout << "--------Begin Programme::execute()" << endl;
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
