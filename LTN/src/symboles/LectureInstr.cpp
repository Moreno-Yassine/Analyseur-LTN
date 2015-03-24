#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/LectureInstr.h"
#include "../../include/symboles/Variable.h"


LectureInstr::LectureInstr()
{

}

LectureInstr::~LectureInstr()
{

}

double LectureInstr::eval()
{

}

bool LectureInstr::setParam(Symbole* symbole, int place)
{
	variableLue = (Variable*)symbole;
	return true;
}

string LectureInstr::print()
{
	string retour ="lire ";
	retour.append(variableLue->print());
	return retour;
}