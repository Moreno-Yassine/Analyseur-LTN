#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/EcritureInstr.h"
#include "../../include/symboles/E.h"
#include <iostream>

EcritureInstr::EcritureInstr()
{
	expressionAEcrire = NULL;
}

EcritureInstr::~EcritureInstr()
{

}

double EcritureInstr::eval()
{
	
}

bool EcritureInstr::setParam(Symbole* symbole, int place)
{
	expressionAEcrire = (E*)symbole;
	return true;
}

bool EcritureInstr::executer()
{
	cout << "-----EcritureInstr::executer()" << endl;
	cout<<expressionAEcrire->print()
		<<" vaut "
		<<expressionAEcrire->eval()
		<<endl;
	return true;
}

string EcritureInstr::print()
{

	cout << "------ EcritureInstr::print()" << endl;

	string retour ="ecrire ";
	//retour.append(expressionAEcrire->print());
	retour.append(";");

	return retour;
}