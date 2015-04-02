#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include <map>

class ProgramManager
{
    public:
        ProgramManager();
        virtual ~ProgramManager();
        void setProgram(Programme* programme);
        void execute();
        void displayProgram();
        void optimise();
        void analyseStatique(map<int,string> &erreurs);
        void afficheVariablesPasDecl(map<int, string> &erreurs);


    private:
        Programme* program;
};

#endif // PROGRAMMANAGER_H
