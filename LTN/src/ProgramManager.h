#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"

class ProgramManager
{
    public:
        ProgramManager();
        virtual ~ProgramManager();

    private:
        Programme program;
};

#endif // PROGRAMMANAGER_H
