#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include "string.h"
#include <map>
#include <cstdlib>
#include <list>
#include "Folder.h"
#include "File.h"
using namespace std;

class Directory 
{
    private:
    map<string, pair<list<Folder>, list<File> > > directoryContents;
    string directoryPath;

    public:
    list<Folder> getFolders() {return directoryContents[directoryPath].first;}
    list<File> getFiles() {return directoryContents[directoryPath].second;}
    string getDirectoryPath() {return directoryPath;}

    void setFolders(list<Folder> fFolder) {directoryContents[directoryPath].first = fFolder;}
    void setFiles(list<File> fFile) {directoryContents[directoryPath].second = fFile;}
    void setDirectoryPath(string newDirectoryPath) {directoryPath = newDirectoryPath+'/';}

    Directory() 
    {
        directoryPath = "root/"; 
        Folder folder("folder1");
        Folder folder2("folder2");
        directoryContents[directoryPath].first.push_back(folder);
        directoryContents[directoryPath].first.push_back(folder2);
        File file("Test.txt");
        directoryContents[directoryPath].second.push_back(file);
    }
    Directory(string dPath) 
    {
        setDirectoryPath(dPath); 
        File file("Test.txt");
        directoryContents[getDirectoryPath()].second.push_back(file);
    }
    void displayDirectoryContents()
    {
        // Get files and folders from directory
        list<Folder> folders = this->getFolders();
        list<File> files = this->getFiles();

        //Get the name of the folders
        for ( Folder& folder : folders )
        {
            cout << folder.getFolderName() << ' ';
        }
        //Get the name of the files
        for ( File& file : files )
        {
            cout << file.getFileName() << ' ';
        }
        if ((folders.size() + files.size()) != 0)
        {
            cout << endl;
        }
    }
    void createFolderAndDirectory(string folderName, string dPath)
    {
        list<Folder> folders = this->getFolders();
        for ( Folder& folder : folders )
        {
            if (folder.getFolderName() == folderName)
            {
                cout << "This folder already exists." << endl;
                return;
            }
        }
        
        folders.push_back(Folder(folderName));
        this->setFolders(folders);

    }
    void moveToDirectory(string dPath)
    {
        list<Folder> folders = this->getFolders();
        string currentDirect = this->getDirectoryPath();
        if (dPath == "..")
        {   
            if (currentDirect == "root/")
            {
                return;
            }
            string findNewPath = currentDirect.substr(0, currentDirect.rfind("/"));
            findNewPath = findNewPath.substr(0, findNewPath.rfind("/"));
            this->setDirectoryPath(findNewPath);
            return;
        }
        for ( Folder& folder : folders )
        {
            if (folder.getFolderName() == dPath)
            {
                setDirectoryPath(currentDirect+dPath);
                return;
            }
        }
        cout << "This directory doesn't exist." << endl;
    }
};

#endif