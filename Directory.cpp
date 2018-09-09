#include "Directory.h"

void Directory::displayDirectoryContents()
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

void Directory::displayAllDirectoryContents()
{
    // Get files and folders from directory
    list<Folder> folders = this->getFolders();
    list<File> files = this->getFiles();

    //Get the name of the folders
    for ( Folder& folder : folders )
    {
        cout << folder.getFolderPermissions() << ' ';
        cout << folder.getFolderName() << ' ';
        cout << folder.getFolderTime();
        
    }
    //Get the name of the files
    for ( File& file : files )
    {
        cout << file.getFilePermissions() << ' ';
        cout << file.getFileName() << ' ';
        cout << file.getFileTime();
        
    }
}

void Directory::createFolderDirectory(string folderName)
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
    remove(folderName.begin(), folderName.end(), '/');
    folders.push_back(Folder(folderName));
    this->setFolders(folders);
}

void Directory::createFile(string fName)
{
    list<File> files = this->getFiles();
    list<Folder> folders = this->getFolders();

    for ( Folder& folder : folders )
    {
        if (folder.getFolderName() == fName)
        {
            folder.setFolderTime();
            this->setFolders(folders);
            return;
        }
    }

    for ( File& file : files )
    {
        if (file.getFileName() == fName)
        {
            file.setFileTime();
            this->setFiles(files);
            return;
        }
    }
    remove(fName.begin(), fName.end(), '/');
    files.push_back(File(fName));
    this->setFiles(files);
}

void Directory::moveToDirectory(string dPath)
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

void Directory::removeDirectory(string dPath)
{
    
    list<Folder> folders = this->getFolders();
    list<File> files = this->getFiles();
    string currentDirect = this->getDirectoryPath();
    for (list<File>::iterator itr = files.begin(); itr != files.end(); ++itr)
    {
        if (dPath == (*itr).getFileName())
        {
            cout << dPath << ": Not a directory." << endl;
            return;
        }
    } 
    for (list<Folder>::iterator itr = folders.begin(); itr != folders.end(); ++itr)
    {
        if (dPath == (*itr).getFolderName())
        {
            directoryContents.erase(getDirectoryPath()+dPath+'/');
            itr = folders.erase(itr);
            this->setFolders(folders);
            return;
        }
    }
    cout << "This directory does not exist." << endl;
}

void Directory::removeFile(string fName)
{
    // Get files from directory
    list<Folder> folders = this->getFolders();
    list<File> files = this->getFiles();
    for (list<Folder>::iterator itr = folders.begin(); itr != folders.end(); ++itr)
    {
        if (fName == (*itr).getFolderName())
        {
            cout << fName << ": Is a directory." << endl;
            return;
        }
    }
    for (list<File>::iterator itr = files.begin(); itr != files.end(); ++itr)
    {
        if (fName == (*itr).getFileName())
        {
            cout << "Found it" << endl;
            itr = files.erase(itr);
            this->setFiles(files);
            return;
        }
    } 
    cout << "This file does not exist." << endl;
}

void Directory::changePermissions(string flag, string fName)
{
    list<Folder> folders = this->getFolders();
    list<File> files = this->getFiles();
    for ( Folder& folder : folders )
    {
        if (folder.getFolderName() == fName)
        {
            folder.setFolderPermissions(flag);
            this->setFolders(folders);
            return;
        }
    }
    for ( File& file : files )
    {
        if (file.getFileName() == fName)
        {
            file.setFilePermissions(flag);
            this->setFiles(files);
            return;
        }
    }
}