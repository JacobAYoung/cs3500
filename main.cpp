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
  string file;
  Directory directory;
  while (quit == false)
  {
    string currentDirectory = directory.getDirectoryPath();
    cout << currentDirectory << " ";
    flag = "";
    file = "";
    getline(cin, command);
    istringstream iss(command);
    iss >> command >> flag >> file;
    if(command == "quit")
    {
      quit = true;
      continue;
    }
    if (command == "ls")
    {
      if (flag == "-l")
      {
        directory.displayAllDirectoryContents();
      } else {
        directory.displayDirectoryContents();
      }
      
    }
    if (command == "mkdir")
    {
      directory.createFolderDirectory(flag);
    }
    if (command == "rmdir")
    {
      directory.removeDirectory(flag);
    }
    if (command == "rm")
    {
      directory.removeFile(flag);
    }
    if (command == "cd")
    {
      directory.moveToDirectory(flag);
    }
    if (command == "chmod")
    {
      directory.changePermissions(flag, file);
    }
    if (command == "touch")
    {
      directory.createFile(flag);
    }
    if (command == "pwd")
    {
      cout << directory.getDirectoryPath() << endl;
    }
  }
  
  


  return 0;
}