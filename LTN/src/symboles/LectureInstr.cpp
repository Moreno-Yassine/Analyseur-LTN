#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/LectureInstr.h"
#include "../../include/symboles/Variable.h"


LectureInstr::LectureInstr()
{
	variableLue = NULL;
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

	cout << "------ LectureInstr::print()" << endl;

	string retour ="lire ";
	retour.append(variableLue->print());
	retour.append(";");
	return retour;
}

bool LectureInstr::executer()
{
	//TODO
	return true;
}
