#include "File.h"

using namespace std;

File::File()
{
    //ctor
}

void File::setPath(string link)
{
    path = link;
}

File::~File()
{
    //dtor
}

void File::openParse()
{
	ifstream myfile;
	myfile.open (path.c_str());
	if (myfile.is_open())
	  {
		//AMINE 


	    myfile.close();
	  }
	else
	{
		throw 0;
	}
}

vector<vector<string> > File::getParsedFiles()
{
	return parsedFiles;
}
