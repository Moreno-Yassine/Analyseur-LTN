#include "Dictionary.h"
#include <iterator>
using namespace std;
Dictionary::Dictionary()
{
	
    mapRegex.insert(make_pair("+", boost::regex("\\+")));
    mapRegex.insert(make_pair("-", boost::regex("-")));
    mapRegex.insert(make_pair("*", boost::regex("\\*")));
    mapRegex.insert(make_pair("/", boost::regex("/")));
    mapRegex.insert(make_pair("=", boost::regex("=")));
    mapRegex.insert(make_pair(":=", boost::regex("(:=)")));
    mapRegex.insert(make_pair(";", boost::regex(";")));
    mapRegex.insert(make_pair(",", boost::regex(",")));
    mapRegex.insert(make_pair("const", boost::regex("const$")));
    mapRegex.insert(make_pair("var", boost::regex("var$")));
	mapRegex.insert(make_pair("z_id", boost::regex("^[a-zA-Z][a-zA-Z0-9\\_]*")));
    mapRegex.insert(make_pair("z_val", boost::regex("^[0-9]+((,|\\.)[0-9]+)?$")));
}

Dictionary::~Dictionary()
{
    //dtor
}

/*
Methode pour checker SYNTAXIQUEMENT les mots composant une ligne
exemple : waitingFor (mots[i],"const") on veut checker si le mot i correspond à "const"
word : mot à tester
exp : expression attendue
*/
bool Dictionary::waitingFor(string word,string exp)
{
	map<string,boost::regex>::iterator it;
	it = mapRegex.find(exp);
	if (it != mapRegex.end())
	{
		if (!checkWordRegex(word,it->second))
		{
			cout << exp +" attendue, "+ word +" trouvé" <<endl;
			return false;		
		}
		return true;	
	}
	else
	{
		cout <<"exp invalide"<<endl;
		return false;
	}
}
bool Dictionary::checkWordRegex(string word, boost::regex match)
{
	try
	{
			if(boost::regex_match(word,match))
			{
				return true;
			}
	}
	catch(std::exception e)
	{
		//throw DictionnaryException;
		cout << e.what() << endl;
	}
	
	return false;
}

/*
Methode pour checker LEXICALEMENT les mots composant une ligne
exemple : waitingFor (mots[i],"const") on veut checker si le mot i correspond à "const"
word : mot à tester
exp : expression attendue
*/

bool Dictionary::checkWord(string word)
{
	try
	{
		map<string, boost::regex>::iterator it;
		for(it=mapRegex.begin(); it!= mapRegex.end(); it++)
		{
			if(boost::regex_match(word,it->second))
			{
				return true;
			}
		}
	}
	catch(std::exception e)
	{
		//throw DictionnaryException;
		cout << e.what() << endl;
	}
	return false;
}
