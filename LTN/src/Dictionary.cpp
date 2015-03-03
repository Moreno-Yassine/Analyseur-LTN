#include "Dictionary.h"
#include <iterator>

Dictionary::Dictionary()
{
	
    mapRegex.insert(make_pair("+", regex("+")));
    mapRegex.insert(make_pair("-", regex("-")));
    mapRegex.insert(make_pair("*", regex("*")));
    mapRegex.insert(make_pair("/", regex("/")));
    mapRegex.insert(make_pair("=", regex("=")));
    mapRegex.insert(make_pair(":=", regex("(:=)")));
    mapRegex.insert(make_pair(";", regex(";")));
    mapRegex.insert(make_pair(",", regex(",")));
    mapRegex.insert(make_pair("const", regex("const$")));
    cout << "Test3" << endl;	
    mapRegex.insert(make_pair("var", regex("var$")));
    cout << "Test" << endl;	
    try
    {
		mapRegex.insert(make_pair("id", regex("^[a-zA-Z][a-zA-Z0-9\\_]*",regex_constants::extended))); //([a-zA-Z0-9\\_]*)
		cout << "Test4" << endl;
	}
	catch (const std::regex_error& e) {
        std::cout << "regex_error caught: " << e.what() << '\n';
        if (e.code() == std::regex_constants::error_brack) {
            std::cout << "The code was error_brack\n";
        }
    }
    	
    mapRegex.insert(make_pair("val", regex("[0-9]+ [\\.] [0-9]*",regex_constants::extended)));
    cout << "Test2" << endl;	
}

Dictionary::~Dictionary()
{
    //dtor
}

bool Dictionary::checkWord(string word)
{
	try
	{
		map<string, regex>::iterator it;
		string var = "*";
		cout << "Result " << regex_search(var,regex("*")) << endl;
		
		for(it=mapRegex.begin(); it!= mapRegex.end(); it++)
		{
			cout << it->first << endl;
			if(regex_match(word,it->second))
			{
				cout << it->first << endl;
				return true;
			}
		}
	}
	catch(std::exception e)
	{
			cout << "dvg"<< e.what() << endl;
	}
	
	cout << "Nothing" << endl;
	return false;
}
