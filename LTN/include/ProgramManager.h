#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"

class ProgramManager
{
    public:
        ProgramManager();
        virtual ~ProgramManager();
        void setProgram(Programme* programme);
        void execute();
        void displayProgram();
        void optimise();
        void analyseStatique();


    private:
        Programme* program;
};

#endif // PROGRAMMANAGER_H
