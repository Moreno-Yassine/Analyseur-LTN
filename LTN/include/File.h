#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

class File
{
    public:
        /* Constructeur par Défaut de la Classe File
         * @return : N/A
         */
        File();

        /* Destructeur de la Classe File
		 * @return : N/A
		 */
        virtual ~File();
		void openParse();
		void setPath(string link);
		vector<vector<string> > getParsedFiles();
		vector<string> getContinueParsedFile();
		void ParsingTest();

    private:
    	string path;
		vector<vector<string> > parsedFiles;
		void procTest();
		void cleaning();
        void Dismantle(vector<string>* array,string* temp);
        bool cleanWord(string tested);
};

#endif // FILE_H
