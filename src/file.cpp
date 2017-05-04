#include "file.h"

using namespace std;

file::File()
{
    m_name = "";
    m_size = 0;
}

file::File(string name, int size)
{
    m_name = name;
    m_size = size;
}

void file::setName(string name)
{
    m_name = name;
}

void file::setSize(int size)
{
    m_size = size;
}

string file::getName()
{
    return m_name;
}

int file::getSize()
{
    return m_size;
}

void file::add_file(sring path, string file_name, int size)
{
    File *addFile = new File(path, file_name, size);
    
    string destination = File.parse_path(path);
    //find parent node    
    folder *add_folder = Folder_Tree.find(destination);
    //insert new file into tree
    Folder_Tree.insert(add_folder, addFile);
    
    //update size of parent folder
    add_folder->setSize(add_folder->getSize() + addFile->getSize());
}
File File::get_file(string path, string file_name)
{
}

list<File> get_files(string path, string file_name)
{
}

void file::delete_file(std::string path, std::string file_name)
{
    string destination = File.parse_path(path);
    
    //store file in pointer to be used
    Folder *parentFolder = Folder_Tree.find(destination)
    File *deletedFile = Folder_Tree.find(file_name);
    
    //adjust size of parent folder before deleting 
    parentFolder->setSize(parentFolder->getSize() - deletedFile->getSize());
    //delete file
    Folder_Tree.erase(Folder_Tree.find(parentFolder, deletedFile);
}
