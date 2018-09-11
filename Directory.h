#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <list>
#include "Folder.h"
#include "File.h"
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Directory 
{
    private:
    //Key: Directory
    //Has a pair of a list of folders and files
    map<string, pair<list<Folder>, list<File> > > directoryContents;
    //The current directory path
    string directoryPath;

    public:
    //Default constructor
    Directory() 
    {
        //Set the default path to root and give it some basic folders and files
        directoryPath = "root/"; 
        Folder folder("folder1");
        Folder folder2("folder2");
        directoryContents[directoryPath].first.push_back(folder);
        directoryContents[directoryPath].first.push_back(folder2);
        File file("Test.txt");
        directoryContents[directoryPath].second.push_back(file);
        
    }
    list<Folder> getFolders() {return directoryContents[directoryPath].first;}
    list<File> getFiles() {return directoryContents[directoryPath].second;}
    string getDirectoryPath() {return directoryPath;}

    //Setters
    void setFolders(list<Folder> fFolder) {directoryContents[directoryPath].first = fFolder;}
    void setFiles(list<File> fFile) {directoryContents[directoryPath].second = fFile;}
    void setDirectoryPath(string newDirectoryPath) {directoryPath = newDirectoryPath+'/';}

    //We display the files and folders names within the directory
    void displayDirectoryContents();
    //Display the directories files and folders with their permissions/last time touched
    void displayAllDirectoryContents();

    //Create a new folder
    void createFolderDirectory(string folderName);
    //Create a new file
    void createFile(string fName);
    //Move to a new directory
    void moveToDirectory(string dPath);

    //Remove a folder within the current directory
    void removeDirectory(string dPath);
    //Remove a file within the current directory
    void removeFile(string fName);
    //Change the permissions of a file/folder
    void changePermissions(string flag, string fName);
};

#endif