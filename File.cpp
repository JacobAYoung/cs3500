#include "File.h"

void File::setFilePermissions(string Flag) 
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
                default:
                    cout << "Error setting permisisons." << endl;
                    break;
            }
        }
    } else {
        cout << "This is not the correct format." << endl;
    }
}