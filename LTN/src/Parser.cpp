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
	cout << "help : description des options disponibles"<<endl;
}

bool* Parser::parsing_options(vector<string> opts)
{
    bool* buffer = new bool[NUM_OPTIONS];
    for (unsigned int i=0; i< opts.size(); i++)
    {
        bool authorized = false;
        for (unsigned int j=0;j< NUM_OPTIONS;j++)
        {
            string buff = opts[i];
            string bug = options->at(j);
            if (buff == bug)
            {
                authorized = true;
                buffer[j] = true;
            }
        }
        if (!authorized)
        {
            throw 0;
        }
    }

    return buffer;
}
