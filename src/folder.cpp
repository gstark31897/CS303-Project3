#include "folder.h"

#include <iostream>
#include <string>

using namespace std;


void Folder::add_folder(string path, string name)
{
    Folder *folder = new Folder(name, 0); 
    
    //string destination = Folder.parse_path(path);
    //find parent node, insert new folder into tree
    //m_folderTree.insert(m_folderTree.find(destination, folder));
}


void Folder::delete_folder(string path, string name)
{
    /*string destination = Folder.parse_path(path);
    
    //store folder pointer to be used
    Folder *parent_folder = Folder_Tree.find(desination); 
    Folder *child_folder = Folder_Tree.find(name); 
    
    //adjust the size of parent folder before the child is deleted
    parent_folder->setSize(parent_folder->getSize() - child_folder(child_folder->getSize());
    //delete folder
    Folder_Tree.erase(Folder_Tree.find(destination), name);*/
}


std::ostream& operator<<(std::ostream &out, const Folder &folder)
{
    return out << folder.getName();
}

