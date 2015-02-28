#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

using namespace std;

class File
{
    public:
        File();
        virtual ~File();

    private:
        string path;
};

#endif // FILE_H
