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
	string retour ="lire ";
	retour.append(variableLue->print());
	retour.append(";");
	return retour;
}

bool LectureInstr::executer()
{
	string value;
	cout << "Rentrez une valeur numérique pour la variable " << variableLue->print() << " : " << endl;
	cin >> value;
	while (!is_number(value))
	{
		cout << "Erreur : La valeur rentrée n'est pas numérique." << endl;
		cout << "Rentrez une valeur numérique pour la variable " << variableLue->print() << " : " << endl;
		cin.ignore();
		cin >> value;
	}

	variableLue->affecter(new Valeur(value), this);

	//cout << variableLue->print() << " = ";
	//cout << variableLue->eval() << endl;

	return true;
}

bool LectureInstr::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
