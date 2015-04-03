#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "symboles/ID_Symboles.h"

#include <map>
#include <iostream>
#include <boost/regex.hpp>

using namespace std;
//using namespace boost;

class Dictionary
{
    public:

        /* Constructeur par Défaut de la Classe Dictionary
         * @return : N/A
         */
        Dictionary();

        /* Destructeur de la Classe Dictionary
         * @return : N/A
         */
        virtual ~Dictionary();

        /* Methode pour checker SYNTAXIQUEMENT les mots composant une ligne exemple : waitingFor (mots[i],"const") on veut checker si le mot i correspond à "const"
         * @param : 
         *          word(string) : mot à tester ;
         *          exp(string) : expression attendue ;
         * @return : Boolean
         */
        bool waitingFor(string word,string exp);

        /* Methode pour identifier le Symbole lu
         * @param : 
         *          word(string) : mot à tester ;
         * @return : IdSymbole (IdSymbole est défini dans la Classe ID_Symboles.h du dossier "symboles")
         */
		IdSymbole checkWord(string word);

    protected:
    
    private:
        
		bool checkWordRegex(string word, boost::regex match);
        map<string,boost::regex> mapRegex;
        map<string, IdSymbole> mapStringIdSymbole;
    
};

#endif // DICTIONARY_H
