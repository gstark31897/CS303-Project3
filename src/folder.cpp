#include "Folder.h"

#include <iostream>
#include <string>

using namespace std;


Folder::Folder(string name, int size): FileObject(name)
{
    m_size = size;
}


void Folder::add_folder(string path, string name)
{
    Folder *folder = new Folder(name, 0); 
    
    string destination = Folder.parse_path(path);
    //find parent node, insert new folder into tree
    Folder_Tree.insert(Folder_Tree.find(destination, folder);
}


void Folder::delete_folder(string path, string name)
{
    string destination = Folder.parse_path(path);
    
    //store folder pointer to be used
    Folder *parent_folder = Folder_Tree.find(desination); 
    Folder *child_folder = Folder_Tree.find(name); 
    
    //adjust the size of parent folder before the child is deleted
    parent_folder->setSize(parent_folder->getSize() - child_folder(child_folder->getSize());
    //delete folder
    Folder_Tree.erase(Folder_Tree.find(destination), name);
}

