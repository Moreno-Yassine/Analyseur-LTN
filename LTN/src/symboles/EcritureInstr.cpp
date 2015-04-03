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
	if(symbole->toString()== "I_ID")
	{
		expressionAEcrire = (Variable*)symbole;
		
	}else if (symbole->toString()== "I_NB")
	{
		expressionAEcrire = (Valeur*)symbole;
		
	}else if (symbole->toString()== "I_EPlus")
	{
		expressionAEcrire = (EPlus*)symbole;
		
	}else if (symbole->toString()== "I_EMult")
	{	
		expressionAEcrire = (EMult*)symbole;
		
	}else if (symbole->toString()== "I_EPar")
	{
		expressionAEcrire = (EParantheses*)symbole;
		
	}else
		expressionAEcrire = (E*)symbole;
	
	return true;
}

bool EcritureInstr::executer()
{
	cout<<expressionAEcrire->print()
		<<" vaut "
		<<expressionAEcrire->eval()
		<<endl;
	return true;
}

string EcritureInstr::print()
{

	//cout << "------ EcritureInstr::print()" << endl;

	string retour ="ecrire ";
	retour.append(expressionAEcrire->print());
	retour.append(";");

	return retour;
}

bool EcritureInstr::checkModifiedConst()
{
	return false;
}

bool EcritureInstr::checkVarPasAffectees(vector<Variable*> variables)
{
	/*if(expressionAEcrire->checkVarPasAffectees())
	{
		return true;
	}*/
	return false;
}
