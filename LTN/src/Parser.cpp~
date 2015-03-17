#include "Parser.h"
#include "Controler.h"

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

void Parser::parsing_options(vector<string> opts)
{
    //AJOUTER : ON NE PEUT PAS AVOIR 2 FOIS LA MEME OPTION -> booleans, exception if déjà true
    for (unsigned int i=0; i< opts.size(); i++)
    {
        if (opts[i].compare(options->at(0)) == 0)
        {
            Controler::enable_o();
        }
        else if (opts[i].compare(options->at(1)) == 0)
        {
            Controler::enable_a();
        }
        else if (opts[i].compare(options->at(2)) == 0)
        {
            Controler::enable_p();
        }
        else if (opts[i].compare(options->at(3)) == 0)
        {
            Controler::enable_e();
        }
        else
        {
            throw 0;
        }
    }

}
