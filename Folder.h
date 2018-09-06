#ifndef FOLDER_H
#define FOLDER_H

 #include <iostream>
// #include "string.h"
// #include <map>
// #include "Folder.h"
// #include "File.h"
// #include <cstdlib>
// #include <map>

using namespace std;

class Folder
{
    string folderName;
    string folderTime;
    public:
    string getFolderTime(){return folderTime;}
    string getFolderName(){return folderName;}

    void setFolderTime(){time_t now = time(NULL);
                    folderTime = ctime(&now);} 
    void setFolderName(string newFolderName){folderName = newFolderName;}
    Folder(){}
    Folder(string fName)
    {
        folderName = fName;
        time_t now = time(NULL);
        folderTime = ctime(&now);
    }
    

};

#endif