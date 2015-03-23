#include "File.h"
#include <vector>
using namespace std;

const string tok = ";";
const string vars = "var";
const string consts = "const";
const string minitok = ",";
const string equals = "=";
const string affct = ":=";

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

}

void File::openParse()
{
	ifstream myfile;
	myfile.open (path.c_str());
	if (myfile.is_open())
	  {  
		string ligne; //variable contenant chaque ligne lue 
            
        //cette boucle s'arrête dès qu'une erreur de lecture survient 
        while ( getline( myfile, ligne ) ) 
        { 
			if(ligne != "")
			{
				vector<string> array;
                stringstream ss(ligne);
                string temp;
                while (ss >> temp)
                {
                	// Tant que le mot n'a pas été consommé entièrement
                	while (temp != "")
                	{
                		// On a détecté :=
	                	if (temp.find(affct) != string::npos)
	                	{
	                		array.push_back(temp.substr(0,temp.find(affct)));
	                		array.push_back(affct);
	                		size_t sub = temp.find(affct)+2;
	                		temp = temp.substr(sub);
	                	}
	                	// On a détecté ,
	                	if (temp.find(minitok) != string::npos)
	                	{
	                		array.push_back(temp.substr(0,temp.find(minitok)));
	                		array.push_back(minitok);
	                		size_t sub = temp.find(minitok)+1;
	                		temp = temp.substr(sub);
	                	}
						// On a détecté =
						if (temp.find(equals) != string::npos)
	                	{
	                		array.push_back(temp.substr(0,temp.find(equals)));
	                		array.push_back(equals);
	                		size_t sub = temp.find(equals)+1;
	                		temp = temp.substr(sub);
	                	}

	                	// On a détecté ;
						if (temp.find(tok) == string::npos)
						{
							array.push_back(temp);
							temp = "";
						}
						else
						{
							array.push_back(temp.substr(0,temp.find(tok)));
							array.push_back(tok);
							temp = "";
						}
                	}
				}
                parsedFiles.push_back(array);
			}                   
        } 
	    myfile.close();
		cleaning();
	  }
	else
	{
		throw 0;
	}
}

vector<string> File::getContinueParsedFile()
{
	vector<string> continueParsedFile;
	for(int i=0; i<parsedFiles.size(); i++)
	{
		for(int j=0; j<parsedFiles[i].size(); j++)
		{
			continueParsedFile.push_back(parsedFiles[i][j]);
		}
	}
	return continueParsedFile;
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
			if (parsedFiles[i][j] != "")
			cout << parsedFiles[i][j] << endl;
			else
			cout << "NULL" << endl;
		}
	}
}

void File::cleaning()
{
	for (unsigned int i = 0;i<parsedFiles.size();i++)
	{
		for (unsigned int j=0;j<parsedFiles[i].size();j++)
		{
			if (parsedFiles[i][j] == "")
			parsedFiles[i].erase(parsedFiles[i].begin()+j);
		}
	}
}
