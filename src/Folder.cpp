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
    FolderObject(folder_name);
    m_folder_name = folder_name;
    m_folder_size = folder_size;
}

void Folder::add_folder(string path, string folder_name)
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
        pArray[i+1] = substr(0, position);
    }
    
    //insert into tree
    Folder_Tree.insert(Folder_tree->local_root, pArray[pCount-1]);
}
    
