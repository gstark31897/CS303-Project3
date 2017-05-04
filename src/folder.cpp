#include "Folder.h"

#include <iostream>
#include <string>

using namespace std;

Folder::Folder()
{
    m_folder_name = "";
    m_folder_size = 0;
}

Folder::Folder(string folder_name, int folder_size)
{
    Object(folder_name);
    m_folder_name = folder_name;
    m_folder_size = folder_size;
}

void Folder::setSize(int size)
{
    m_folder_size = size;
}

void Folder::setName(string name)
{
    m_folder_name = name;
}

int Folder::getSize()
{
    return m_folder_size;
}

string Folder::getName()
{
    return m_folder_name;
}

void Folder::add_folder(string path, string folder_name)
{
    Folder *folder = new Folder(folder_name, 0); 
    
    string destination = Folder.parse_path(path);
    //find parent node, insert new folder into tree
    Folder_Tree.insert(Folder_Tree.find(destination, folder);
}

void Folder::delete_folder(string path, string folder_name)
{
    string destination = Folder.parse_path(path);
    
    //store folder pointer to be used
    Folder *parent_folder = Folder_Tree.find(desination); 
    Folder *child_folder = Folder_Tree.find(folder_name); 
    
    //adjust the size of parent folder before the child is deleted
    parent_folder->setSize(parent_folder->getSize() - child_folder(child_folder->getSize());
    //delete folder
    Folder_Tree.erase(Folder_Tree.find(destination), folder_name);
}



