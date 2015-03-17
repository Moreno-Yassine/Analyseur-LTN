#include "Dictionary.h"
#include <iterator>

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
}

Dictionary::~Dictionary()
{
    //dtor
}

bool Dictionary::checkWord(string word)
{
	try
	{
		map<string, boost::regex>::iterator it;
		
		for(it=mapRegex.begin(); it!= mapRegex.end(); it++)
		{
			if(boost::regex_match(word,it->second))
			{
				//Pour Tester
				cout <<"Clé = " <<  it->first << endl;
				cout << "Result = " << boost::regex_match(word,it->second) << endl;
				return true;
			}
		}
	}
	catch(std::exception e)
	{
		//throw DictionnaryException;
		cout << e.what() << endl;
	}
	
	cout << "Nothing" << endl;
	return false;
}
