#include "Folder.h"

void Folder::setFolderPermissions(string Flag) 
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