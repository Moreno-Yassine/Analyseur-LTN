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
        Dictionary();
        virtual ~Dictionary();

        bool waitingFor(string word,string exp);
		bool checkWord(string word);

    protected:
    private:
		bool checkWordRegex(string word, boost::regex match);
        map<string,boost::regex> mapRegex;
        map<string, IdSymbole> mapStringIdSymbole;
    
};

#endif // DICTIONARY_H
