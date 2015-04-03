#ifndef PARSER_H
#define PARSER_H
#define NUM_OPTIONS 4
#define MAX_ARGS 6

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Parser
{
    public:
        /* Constructeur par Défaut de la Classe Parser
         * @return : N/A
         */
        Parser();

     	 /* Destructeur de la Classe Parser
         * @return : N/A
         */
        virtual ~Parser();

		void show_options();
		void parsing_options(vector<string> opts);

    private:
		vector<string>* options;
};

#endif // PARSER_H
