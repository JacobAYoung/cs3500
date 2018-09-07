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
        cout << Flag.length() << endl;
        if (Flag.length() == 3)
        { 
            cout << "test" << endl;
            for (int i = 0; i < Flag.length(); i++)
            {
                cout << "Test2" << endl;
                cout << i << endl;
                cout << Flag[i] << endl;
                cout << Flag[i] - 48 << endl;
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
                        permissions[i].insert(i, "-wx");
                        break;
                    case 4:
                        cout << "folder4" << endl;
                        permissions[i] = ("r--");
                        break;
                    case 5:
                        permissions[i].insert(i, "r-x");
                        break;
                    case 6:
                        cout << "folder6" << endl;
                        permissions[i] = ("rw-");
                        break;
                    case 7:
                        permissions[i].insert(i, "rwx");
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
        cout << "set folder permissions" << endl;
        this->setFolderPermissions("644");
    }
    

};

#endif