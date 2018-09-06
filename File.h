#ifndef FILE_H
#define FILE_H

#include <iostream>
// #include "string.h"
// #include <map>
 #include <ctime>
// #include <cstdlib>
// #include <list>

using namespace std;

class File
{
    string fileName;
    string fileTime;
    public:
    string getFileTime(){return fileTime;}
    string getFileName(){return fileName;}

    void setFileTime(){time_t now = time(NULL);
                    fileTime = ctime(&now);} 
    void setFileName(string newFileName){fileName = newFileName;}
    File(){}
    File(string fName)
    {
        fileName = fName;
        time_t now = time(NULL);
        fileTime = ctime(&now);
    }
};

#endif