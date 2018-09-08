#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>

using namespace std;

class Folder
{
    string folderName;
    string folderTime;
    string permissions[3] = {};
    public:
    string getFolderTime(){return folderTime;}
    string getFolderName(){return folderName;}
    string getFolderPermissions(){return 'd'+permissions[0]+permissions[1]+permissions[2];}
    void setFolderTime(){time_t now = time(NULL);
                    folderTime = ctime(&now);} 
    void setFolderName(string newFolderName){folderName = newFolderName;}
    void setFolderPermissions(string Flag) 
    {
        if (Flag.length() == 3)
        { 
            for (int i = 0; i < Flag.length(); i++)
            {
                switch (Flag[i] - 48)
                {
                    case 0:
                        permissions[i] = ("---");
                        break;
                    case 1:
                        permissions[i] = ("--x");
                        break;
                    case 2:
                        permissions[i] = ("-w-");
                        break;
                    case 3:
                        permissions[i] = ("-wx");
                        break;
                    case 4:
                        permissions[i] = ("r--");
                        break;
                    case 5:
                        permissions[i] = ("r-x");
                        break;
                    case 6:
                        permissions[i] = ("rw-");
                        break;
                    case 7:
                        permissions[i] = ("rwx");
                        break;
                }
            }
        } else {
            cout << "This is not the correct format." << endl;
        }
    }
    Folder(){}
    Folder(string fName)
    {
        folderName = fName;
        time_t now = time(NULL);
        folderTime = ctime(&now);
        this->setFolderPermissions("644");
    }
    

};

#endif