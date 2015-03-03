#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class File
{
    public:
        File();
        virtual ~File();
	void openParse();
	void setPath(string link);
	vector<vector<string> > getParsedFiles();

    private:
        string path;
	vector<vector<string> > parsedFiles;
};

#endif // FILE_H
