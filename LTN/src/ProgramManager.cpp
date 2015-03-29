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

void ProgramManager::analyseStatique()
{

}

void ProgramManager::execute()
{
    cout << "--------Begin ProgramManager::execute()" << endl;
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

