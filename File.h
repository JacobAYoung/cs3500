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
    string permissions[3] = {};
    public:
    string getFileTime(){return fileTime;}
    string getFileName(){return fileName;}
    string getFilePermissions(){return '-'+permissions[0]+permissions[1]+permissions[2];}
    void setFileTime(){time_t now = time(NULL);
                    fileTime = ctime(&now);} 
    void setFileName(string newFileName){fileName = newFileName;}
    File(){
        //setFilePermissions("644");
    }
    File(string fName)
    {
        fileName = fName;
        time_t now = time(NULL);
        fileTime = ctime(&now);
        setFilePermissions("644");
    }
    void setFilePermissions(string Flag) 
    {
        if (Flag.length() == 3)
        { 
            for (int i = 0; i < Flag.length(); i++)
            {
                switch (Flag[i] - 48)
                {
                    case 0:
                        this->permissions[i] = ("---");
                        break;
                    case 1:
                        this->permissions[i] = ("--x");
                        break;
                    case 2:
                        this->permissions[i] = ("-w-");
                        break;
                    case 3:
                        this->permissions[i] = ("-wx");
                        break;
                    case 4:
                        this->permissions[i] = ("r--");
                        break;
                    case 5:
                        this->permissions[i] = ("r-x");
                        break;
                    case 6:
                        this->permissions[i] = ("rw-");
                        break;
                    case 7:
                        this->permissions[i] = ("rwx");
                        break;
                }
            }
        } else {
            cout << "This is not the correct format." << endl;
        }
    }
};

#endif