#include "../include/ProgramManager.h"

ProgramManager::ProgramManager()
{
    constModif = false;
}

ProgramManager::~ProgramManager()
{

}

void ProgramManager::setProgram(Programme* programme)
{
    this->program = programme;
}

bool ProgramManager::analyseStatique(map<int,string> &erreurs)
{
    afficheVariablesPasDecl(erreurs);
    afficheDoublesDecl();
    if(program -> checkModifiedConst())
        constModif = true;

    /* if(program -> checkVarPasAffectees())
    {
        //cerr << "------------" << endl;
    }*/

    if(erreurs.size()>0)
        throw 0;

    if(doublons.size()>0 || constModif)
        return true;

    return false;
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

    cerr << varPasDecl << " variables (ou constantes) pas déclarées";

    if(err)
    {
       cerr << ": ";
    }

    cerr << endl;


    for(int i=0; i<(int)names.size(); i++)
    {
		cerr << "\"" << names[i] << "\"" << endl;
    }

    cerr << "------------" << endl;
}

void ProgramManager::afficheDoublesDecl()
{
    bool err = false;
    int varDeclMult = 0;
	vector<string> names;

    if(doublons.size()>0)
    {
        names.push_back(doublons[0]);
        varDeclMult++;
        err = true;
    }

    bool trouve = false;

    for(int i=1; i<(int)doublons.size(); i++)
    {
        for(int j=0; j<(int)names.size(); j++)
        {
            if(doublons[i] == names[j])
            {
                trouve = true;
            }
        }
        if(!trouve)
        {
            names.push_back(doublons[i]);
            varDeclMult++;
        }

        trouve = false;
    }

    cerr << varDeclMult << " variables (ou constantes) ayant une déclaration multiple";

    if(err)
    {
       cerr << ": ";
    }

    cerr << endl;

    for(int i=0; i<(int)names.size(); i++)
    {
		cerr << "\"" << names[i] << "\"" << endl;
    }

    cerr << "------------" << endl;
}

