#include "../include/File.h"
#include <vector>
#include <ctype.h>
#include <locale>
using namespace std;

const string tok = ";";
const string vars = "var";
const string consts = "const";
const string minitok = ",";
const string equals = "=";
const string affct = ":=";
const string plusLut = "+";
const string minusLut = "-";
const string multiplyLut = "*";
const string divideLut = "/";
const string paro = "(";
const string parf = ")";

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
                    if(cleanWord(temp))
                    {
                        array.push_back(temp);
                    }
                    else
                    {
                       Dismantle(&array,&temp); 
                    }
		}
                parsedFiles.push_back(array);
			}                   
        } 
	    myfile.close();
		cleaning();
		ParsingTest();
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

void File::Dismantle(vector<string>* array,string* temp)
{
	if((*temp).find(affct)!=string::npos)
	{
		size_t found = (*temp).find(affct);
		if((*temp).substr(0,found-1) != "")
		{
			(*array).push_back((*temp).substr(0,found-1));
		}
		(*array).push_back(affct);
		string remaining;
		remaining = (*temp).substr(found+2);
		Dismantle(array,&remaining);
	}
	else
	{
		size_t found = (*temp).find_first_of("+-*/=(),;");
		if (found != std::string::npos)
		{
			string flush = "";
			for(size_t found = 0;found<(*temp).size();found++)
			{
				if(!isalpha((*temp)[found])&&!isdigit((*temp)[found]))
				{
					if(flush!="")
					{
						(*array).push_back(flush);
					}
					flush ="";
					(*array).push_back(string(1,(*temp)[found]));
				}
				else
				{
					flush +=(*temp)[found];
				}
			}
			// On flush ce qui reste
			(*array).push_back(flush);
		}
		else
		{
			 (*array).push_back((*temp));
		}
	}   
}

bool File::cleanWord(string tested)
{
    if (tested.find_first_of("+-*/=(),;") != string::npos || tested.find(affct) != string::npos )
    {
        return false;
    }
    return true;
}

