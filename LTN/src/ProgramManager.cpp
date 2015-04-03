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
    if(program -> checkModifiedConst())
    {
        cerr << "------------" << endl;

        // On peut faire throw 0 pour déclancher une exception
    }
    /*if(program -> checkVarPasAffectees())
    {
        //cerr << "------------" << endl;
    }

	for(int i=0; i<doublons.size();i++)
		cerr << "Double déclaration de la variable : " << doublons[i] << endl;
    /*if(program -> checkDoublons())
    {

    }*/
}

void ProgramManager::execute()
{
	(this->program)->executer();
}

void ProgramManager::displayProgram()
{
    (this->program)->display();
}

void ProgramManager::optimise()
{

}

void ProgramManager::afficheVariablesPasDecl(map<int,string> &erreurs)
{
    bool err = false;
    int varPasDecl = 0;
    vector<string> names;

    if(erreurs.size()>0)
    {
        names.push_back(erreurs[0]);
        varPasDecl++;
        err = true;
    }

    bool trouve = false;

    for(int i=1; i<(int)erreurs.size(); i++)
    {
        for(int j=0; j<(int)names.size(); j++)
        {
            if(erreurs[i] == names[j])
            {
                trouve = true;
            }
        }
        if(!trouve)
        {
            names.push_back(erreurs[i]);
            varPasDecl++;
        }

        trouve = false;
    }

    cerr << varPasDecl << " variables (ou constantes) pas déclarées : " << endl;

    for(int i=0; i<(int)names.size(); i++)
    {
		cerr << "\"" << names[i] << "\"" << endl;
    }

    cerr << "------------" << endl;

    if (err)
        throw 0;

}

