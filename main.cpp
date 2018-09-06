#include <iostream>
//#include "string.h"
// #include <cstdlib>
#include <sstream>
#include "Directory.h"

using namespace std;

int main()
{
  bool quit = false;
  string command;
  string flag;
  Directory directory;
  while (quit == false)
  {
    
    
    string currentDirectory = directory.getDirectoryPath();
    //directory.DisplayDirectoryContents();
    cout << currentDirectory << endl;

    getline(cin, command);
    istringstream iss(command);
    iss >> command >> flag;
    if(command == "quit")
    {
      quit = true;
      continue;
    }
    if (command == "ls")
    {
      directory.displayDirectoryContents();
    }
    if (command == "mkdir")
    {
      directory.createFolderAndDirectory(flag, currentDirectory+flag+'/');
    }
    if (command == "cd")
    {
      directory.moveToDirectory(flag);
    }
  }
  
  


  return 0;
}