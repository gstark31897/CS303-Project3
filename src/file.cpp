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
    file *addFile = new File(path, file_name, size);
    int pCount = 0; 
    
    for(int i = 0; i < path.size(); i++)
    {
        if(path[i] == '/')
        {
            pCount++;
        }
    }
    
    pCount += 1;
    string pArray[pCount]; 
    pArray[0] = path; 
    
    for(int j = 0; j < pCount; j++)
    {
        int position = pArray[i].find('/');
        pArray[i+1] = substr(position, pArray[i].size());
    }
        
    //find parent node    
    folder *add_folder = Folder_Tree.find(pArray[pCount - 1]);
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
    int pCount = 0; 
    
    for(int i = 0; i < path.size(); i++)
    {
        if(path[i] == '/')
        {
            pCount++;
        }
    }
    
    pCount += 1;
    string pArray[pCount]; 
    pArray[0] = path; 
    
    for(int j = 0; j < pCount; j++)
    {
        int position = pArray[i].find('/');
        pArray[i+1] = substr(position, pArray[i].size());
    }
    
    //store file in pointer to be used
    folder *parentFolder = Folder_Tree.find(pArray[pCount - 1])
    file *deletedFile = Folder_Tree.find(file_name);
    
    //adjust size of parent folder before deleting 
    parentFolder->setSize(parentFolder->getSize() - deletedFile->getSize());
    //delete file
    Folder_Tree.erase(Folder_Tree.find(parentFolder, deletedFile);
}
