#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/AffectationInstr.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/E.h"

AffectationInstr::AffectationInstr()
{
	expressionAffectee = new E();
	variableSeFaisantAffecter = NULL;
}

AffectationInstr::~AffectationInstr()
{

}


double AffectationInstr::eval()
{
	
}

bool AffectationInstr::executer()
{
	double valeurCourante = expressionAffectee->eval();
	//TODO
	return true;
}
