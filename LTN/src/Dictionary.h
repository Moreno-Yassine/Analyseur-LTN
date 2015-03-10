#ifndef DICTIONARY_H
#define DICTIONARY_H

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

        bool checkWord(string word);

    protected:
    private:
        map<string,boost::regex> mapRegex;
    
};

#endif // DICTIONARY_H
