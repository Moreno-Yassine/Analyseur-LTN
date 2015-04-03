#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include <map>
#include <vector>

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
		void setDoublons(vector<string> listeDoublons) {doublons = listeDoublons;};


    private:
        Programme* program;
		vector<string> doublons;
};

#endif // PROGRAMMANAGER_H
