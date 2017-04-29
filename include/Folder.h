#ifndef H_FOLDER
#define H_FOLDER

#include "File.h"
#include "AVL_Tree.h"
#include "fileobject.h"
#include <iostream>
#include <string>
#include <list>

class Folder : public FileObject
{
private:
    std::string m_folder_name;
    int m_folder_size;
    AVL_Tree<Folder> Folder_tree; 
    AVL_Tree<File> File_Tree;
    
public:
    Folder();
    Folder(std::string folder_name, int folder_size);
    
    void add_folder(std::string path, std::string folder_name);
    void delete_folder(std::string path, std::string folder_name);
};

#endif
