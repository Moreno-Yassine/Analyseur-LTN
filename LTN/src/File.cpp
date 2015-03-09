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

void File::procTest()
{
      for (int i=0; i<parsedFiles.size();i++)
      {
            for (int j=0; j<parsedFiles[i].size(); j++)
            cout << parsedFiles[i][j] <<endl;
            
            cout << "Fin de ligne"<<endl;
      }
      
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
                   vector<string> array;
                   stringstream ss(ligne);
                   string temp;
                   while (ss >> temp)
                   array.push_back(temp); // done! now array={mot1,mot2,mot3,mot4,mot5,...}
                   parsedFiles.push_back(array);                   
                } 
	    myfile.close();
	    procTest();
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
