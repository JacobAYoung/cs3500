#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <ctime>

using namespace std;

class Folder
{
    private:
    string folderName;
    string folderTime;
    string permissions[3] = {};
    public:
    //Default constructor
    Folder(){}
    Folder(string fName)
    {
        folderName = fName;
        //Set the current folder time
        time_t now = time(NULL);
        folderTime = ctime(&now);
        //Set the folder's permissions
        setFolderPermissions("644");
    }
    string getFolderTime(){return folderTime;}
    string getFolderName(){return folderName;}
    string getFolderPermissions(){return 'd'+permissions[0]+permissions[1]+permissions[2];}
    
    void setFolderTime(){time_t now = time(NULL); folderTime = ctime(&now);} 
    //Set foldername
    void setFolderName(string newFolderName){folderName = newFolderName;}
    //Set folder permissions
    void setFolderPermissions(string Flag);
    
    

};

#endif