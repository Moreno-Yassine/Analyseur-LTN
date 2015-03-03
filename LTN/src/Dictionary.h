#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <map>
#include <iostream>
#include <regex>

using namespace std;

class Dictionary
{
    public:
        Dictionary();
        virtual ~Dictionary();
        bool checkWord(string word);
    protected:
    private:
    map<string,regex> mapRegex;
    
};

#endif // DICTIONARY_H
