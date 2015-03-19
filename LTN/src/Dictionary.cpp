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
    mapRegex.insert(make_pair("lire", boost::regex("lire[' ']+")));
    mapRegex.insert(make_pair("ecrire", boost::regex("ecrire[' ']+")));
	mapRegex.insert(make_pair("z_id", boost::regex("^[a-zA-Z][a-zA-Z0-9\\_]*")));
    mapRegex.insert(make_pair("z_val", boost::regex("^[0-9]+((,|\\.)[0-9]+)?$")));

    mapStringIdSymbole.insert(make_pair("+", I_pls));
    mapStringIdSymbole.insert(make_pair("-", I_mns));
    mapStringIdSymbole.insert(make_pair("*", I_mul));
    mapStringIdSymbole.insert(make_pair("/", I_div));
    mapStringIdSymbole.insert(make_pair("=", I_egl));
    mapStringIdSymbole.insert(make_pair(":=", I_pegl));
    mapStringIdSymbole.insert(make_pair(";", I_pvrg));
    mapStringIdSymbole.insert(make_pair(",", I_vrg));
    mapStringIdSymbole.insert(make_pair("const", I_const));
    mapStringIdSymbole.insert(make_pair("var", I_VAR));
    mapStringIdSymbole.insert(make_pair("lire", I_lire));
    mapStringIdSymbole.insert(make_pair("ecrire", I_ecrire));
	mapStringIdSymbole.insert(make_pair("z_id", I_ID));
    mapStringIdSymbole.insert(make_pair("z_val", I_NB));
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

IdSymbole Dictionary::checkWord(string word)
{
	try
	{
		map<string, boost::regex>::iterator it;
		for(it=mapRegex.begin(); it!= mapRegex.end(); it++)
		{
			if(boost::regex_match(word,it->second))
			{
				return mapStringIdSymbole.find(it->first)->second;
			}
		}
	}
	catch(std::exception e)
	{
		//throw DictionnaryException;
		cout << e.what() << endl;
	}
	return IdSymbole::I_NULL;
}
