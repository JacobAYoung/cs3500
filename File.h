#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <ctime>

using namespace std;

class File
{
    private:
    //File name
    string fileName;
    //File time
    string fileTime;
    //File permissions
    string permissions[3] = {};
    public:

    //Default constructor
    File(){}
    //Constructor
    File(string fName)
    {
        fileName = fName;
        //Gets the current time and sets it to the file object
        time_t now = time(NULL);
        fileTime = ctime(&now);
        //Setting standard file permissions
        setFilePermissions("644");
    }
    string getFileTime(){return fileTime;}
    string getFileName(){return fileName;}
    //Return the file permissions
    //The '-' is representing the that this is a file and not a directory
    string getFilePermissions(){return '-'+permissions[0]+permissions[1]+permissions[2];}
    void setFileTime(){time_t now = time(NULL);
                    fileTime = ctime(&now);} 
    void setFileName(string newFileName){fileName = newFileName;}
    
    //Set file permissions
    void setFilePermissions(string Flag);
};

#endif