#include "../../include/symboles/Li.h"

Li::Li() : Symbole(I_Li, "I_Li")
{

}

Li::~Li()
{
	for(int i=0;i<(int)listeInstructions.size();i++)
		delete listeInstructions[i];
}

bool Li::setParam(Symbole* s, int noPlace)
{
	listeInstructions.push_back((Instruction*)s);
	return true;
}

bool Li::executer()
{
	for(int i=0;i<(int)listeInstructions.size();i++)
		if(!listeInstructions[i]->executer())
			return false;
	
	return true;
}

bool Li::display()
{
	//cout << "--------Begin Li::display()" << endl;
	//cout << "--------Li::display()::listeInstructions size : " << (int)listeInstructions.size() << endl;
	for(int i=0;i<(int)listeInstructions.size();i++)
		cout << listeInstructions[i]->print() <<endl;

	return true;
}