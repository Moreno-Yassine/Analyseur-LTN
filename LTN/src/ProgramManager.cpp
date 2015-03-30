#include "../include/ProgramManager.h"

ProgramManager::ProgramManager()
{

}

ProgramManager::~ProgramManager()
{

}

void ProgramManager::setProgram(Programme* programme)
{
    this->program = programme;
}

void ProgramManager::analyseStatique(map<int,string> &erreurs)
{
    afficheVariablesPasDecl(erreurs);
}

void ProgramManager::execute()
{
    //cout << "--------Begin ProgramManager::execute()" << endl;
	(this->program)->executer();
}

void ProgramManager::displayProgram()
{
    //cout << "--------Begin ProgramManager::displayProgram()" << endl;
    (this->program)->display();
}

void ProgramManager::optimise()
{

}

void ProgramManager::afficheVariablesPasDecl(map<int,string> &erreurs)
{
    cerr << erreurs.size() << " variables (ou constantes) pas déclarées : " << endl;

    for(int i=0; i< erreurs.size(); i++)
    {
		cerr << "\"" << erreurs[i] << "\"" << endl;
    }

    cerr << "------------" << endl;


}

