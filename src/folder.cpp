#include "folder.h"

#include <iostream>
#include <string>

using namespace std;


void Folder::add_folder(string path, string name)
{
    if (path == "")
    {
        m_folderTree.insert(new Folder(name, 0));
        cout << "No path, inserting here" << endl;
    }
    else
    {
        string front = path_pop(path);
        if (front == getName())
        {
            cout << "Myself, inserting to self: " << path << endl;
            front = path_pop(path);
            add_folder(path, name);
        }
        else
        {
            cout << "Looking for folder: " << path << endl;
            Folder *subFolder = m_folderTree.find(new Folder(front, 0));
        }
    }
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

