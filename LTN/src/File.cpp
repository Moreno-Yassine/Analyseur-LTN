#include "File.h"

using namespace std;

const string tok = ";";

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
		    string ligne; // variable contenant chaque ligne lue 
            
                // cette boucle s'arrête dès qu'une erreur de lecture survient 
                while ( getline( myfile, ligne ) ) 
                { 
			if(ligne != "")
			{
				vector<string> array;
                   		stringstream ss(ligne);
                  		string temp;
                   		while (ss >> temp)
                   		{
					if (temp.find(tok) == string::npos)
					{
						array.push_back(temp);
					}
					else
					{
						array.push_back(temp.substr(0,temp.find(tok)));
						array.push_back(tok);
					}
				}
                   		parsedFiles.push_back(array);
			}                   
                } 
	    myfile.close();
	    ParsingTest();
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

void File::ParsingTest()
{
	for (unsigned int i = 0;i<parsedFiles.size();i++)
	{
		for (unsigned int j=0;j<parsedFiles[i].size();j++)
		{
			cout << parsedFiles[i][j] << endl;
		}
	}
}
