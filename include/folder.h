#ifndef H_FOLDER
#define H_FOLDER

#include "file.h"
#include "AVL_Tree.h"
#include "fileobject.h"
#include <iostream>
#include <string>

class Folder : public FileObject
{
private:
    int m_size;
    AVL_Tree<Folder*> m_folderTree; 
    AVL_Tree<File> m_fileTree;
    
public:
    Folder(): FileObject("") {};
    Folder(std::string name, int size): FileObject(name) {};
    
    //getters/setters
    void setSize(int size) { m_size = size; };
    int getSize() { return m_size; };
    
    void add_folder(std::string path, std::string folder_name);
    void delete_folder(std::string path, std::string folder_name);

    void add_file(std::string path, std::string file_name, int size) {};
    File get_file(std::string path, std::string file_name) {};
    std::list<File> get_files(std::string path, std::string file_name) {};
    void delete_file(std::string path, std::string file_name) {};

    friend std::ostream& operator<<(std::ostream &out, const Folder &folder);
};

#endif
