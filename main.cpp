#include <iostream>
//#include "string.h"
// #include <cstdlib>
#include <sstream>
#include "Directory.h"
#include "Memory.h"

using namespace std;

int main()
{
  bool quit = false;
  string command;
  string flag;
  string file;
  Directory directory;
  Memory memory;
  while (quit == false)
  {
    string currentDirectory = directory.getDirectoryPath();
    //Spits out the current directory each time we do a command
    cout << currentDirectory << " ";
    //Resets the flag and file names
    flag = "";
    file = "";
    getline(cin, command);
    istringstream iss(command);
    //Parse through the text inputted 
    iss >> command >> flag >> file;
    if(command == "quit")
    {
      /* 
      Description: Quits the progream
      */
      quit = true;
      continue;
    } else if (command == "ls") {
      /* 
      Description: Lists out all of the contents of the directory
      Example: ls <optionalflag>>
               ls file/folder names
               ls -l to list out permissions/date last changed
      */
      if (flag == "-l")
      {
        directory.displayAllDirectoryContents();
      } else {
        directory.displayDirectoryContents();
      }
      
    } else if (command == "mkdir") {
      /* 
      Description: Creates a new folder/directory
      Example: mkdir <foldername>
               mkdir folder1
      */
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        directory.createFolderDirectory(flag);
      } else {
        cout << "Error creating folder." << endl;
      }
    } else if (command == "rmdir") {
      /* 
      Description: Removes a folder/directory
      Example: rmdir <foldername>
               rmdir folder1
      */
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        directory.removeDirectory(flag);
      } else {
        cout << "Error removing directory." << endl;
      }
    } else if (command == "rm") {
      /* 
      Description: Removes a file from the directory.
      Example: rm <filename>
               rm example.txt
      */
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        directory.removeFile(flag);
      } else {
        cout << "Error removing file." << endl;
      }
    } else if (command == "cd") {
      /* 
      Description: Moves from a directory to another directory
      Example: cd <foldername>
               cd folder1
      */
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        directory.moveToDirectory(flag);
      } else {
        cout << "Error moving to directory." << endl;
      }
    } else if (command == "chmod") {
      /* 
      Description: Changes the permissions of a file/folder
      Example: chmod <permissions set> <filename>
               chmod 644 file.txt
      */
      if (flag != "" and flag != " " and flag.length() != 0 and file.length() != 0 and file != "" and file != " ")
      {
        directory.changePermissions(flag, file);
      } else {
        cout << "Error changing permissions." << endl;
      }
    } else if (command == "touch") {
      /* 
      Description: Creates a new file or updates the file time
      Example: touch <filename>
               touch example.txt
      */
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        directory.createFile(flag);
      } else {
        cout << "Error creating file." << endl;
      }
      
    } else if (command == "pwd") {
      /* 
      Description: Spits out the current directory
      Example: pwd
      */
      cout << directory.getDirectoryPath() << endl;
    } else if (command == "memload") {
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        vector<string> content = memory.loadFile(flag);
        memory.setAllocationAlgorithm(content);
        memory.setMemorySize(content);
        memory.fillVector(memory.getMemorySize());
        vector<int> trace = memory.getTraceMap();
        memory.setTrace(content, 2);
        memory.firstFitAlgorithm(memory.getTrace(), trace, memory.getMemorySize(), memory.getTimeStep());
      } else {
        cout << "Error loading file." << endl;
      }
    } else if (command == "memstep") {
      if (flag != "" and flag != " " and flag.length() != 0)
      {
        int timeStep = memory.getTimeStep();
        timeStep += stoi(flag);
        memory.setTimeStepNumber(timeStep);
        memory.firstFitAlgorithm(memory.getTrace(), memory.getTraceMap(), memory.getMemorySize(), memory.getTimeStep());
        memory.setLastTimeStep(timeStep);
      } else {
        cout << "Error" << endl;
      }
    } else {
      cout << "Not a valid command." << endl;
    }
  }
  
  


  return 0;
}