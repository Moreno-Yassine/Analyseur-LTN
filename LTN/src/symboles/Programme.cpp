#include "../../include/symboles/Programme.h"

Programme::Programme() : Symbole(I_P, "I_P")
{

}

Programme::~Programme()
{
	delete ptLd;
	delete ptLi;
}

bool Programme::setParam(Symbole* symbole, int place)
{
	if(place==1)
		ptLd = (Ld*)symbole;
	else if(place==2)
		ptLi = (Li*)symbole;
	else
		return false;

	return true;
}

bool Programme::executer()
{
	if(!ptLd->executer())
		return false;
	if(!ptLi->executer())
		return false;
	return true;
}