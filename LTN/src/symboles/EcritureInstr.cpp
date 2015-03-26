#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/EcritureInstr.h"
#include "../../include/symboles/E.h"
#include <iostream>

EcritureInstr::EcritureInstr()
{
	expressionAEcrire = new E();
}

EcritureInstr::~EcritureInstr()
{

}

double EcritureInstr::eval()
{
	
}


bool EcritureInstr::executer()
{
	cout<<expressionAEcrire->print()
		<<" vaut "
		<<expressionAEcrire->eval()
		<<endl;
	return true;
}
