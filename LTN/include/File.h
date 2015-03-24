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
        File();
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
};

#endif // FILE_H