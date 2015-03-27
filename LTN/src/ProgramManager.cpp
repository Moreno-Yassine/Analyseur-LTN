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
	(this->program)->executer();
}

void ProgramManager::displayProgram()
{

}

void ProgramManager::optimise()
{

}

