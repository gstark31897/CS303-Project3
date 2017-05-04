#include "folder.h"

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
    
    int pCount = 0; 
    
    for(size_t i = 0; i < path.size(); i++)
    {
        if(path[i] == '/')
        {
            pCount++;
        }
    }
    
    pCount += 1;
    string pArray[pCount]; 
    pArray[0] = path; 
    
    for(size_t j = 0; j < pCount; j++)
    {
        size_t position = pArray[j].find('/');
        pArray[j+1] = substr(position, pArray[j].size());
    }
    
    //find parent node, insert new folder into tree
    Folder_Tree.insert(Folder_Tree.find(pArray[pCount - 1], folder);
}

void Folder::delete_folder(string path, string name)
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
    
    //store folder pointer to be used
    Folder *parent_folder = Folder_Tree.find(pArray[pCount - 1]); 
    Folder *child_folder = Folder_Tree.find(name); 
    
    //adjust the size of parent folder before the child is deleted
    parent_folder->setSize(parent_folder->getSize() - child_folder(child_folder->getSize());
    //delete folder
    Folder_Tree.erase(Folder_Tree.find(pArray[pCount - 1]), name);
}


ostream& operator<<(ostream &out, const Folder &folder)
{
    return out << folder.m_name;
}
