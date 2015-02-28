#include "Parser.h"

Parser::Parser()
{
	options = new vector<string>(NUM_OPTIONS);
	options->at(0)= "-o";
	options->at(1)= "-a";
	options->at(2)= "-p";
	options->at(3)= "-e";
}

Parser::~Parser()
{
	delete[] options;
}

void Parser::show_options()
{
	cout << "Options disponibles : " <<endl;
	cout << "----------------------" <<endl;
	cout << options->at(0)+" : desc" << endl;
	cout << options->at(1)+" : desc" << endl;
	cout << options->at(2)+" : desc" << endl;
	cout << options->at(3)+" : desc" << endl;
}
