#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/AffectationInstr.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"
#include "../../include/symboles/E.h"
#include <sstream>

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
	variableSeFaisantAffecter->eval();
}

bool AffectationInstr::executer()
{
	double valeurCourante = expressionAffectee->eval();
	stringstream ss;
	ss<<valeurCourante;
	Valeur* val = new Valeur(ss.str());
	variableSeFaisantAffecter->affecter(val,this);
	return true;
}
