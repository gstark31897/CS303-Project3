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
    AVL_Tree<Folder*> m_folderTree; 
    AVL_Tree<File*> m_fileTree;
    
public:
    Folder(): FileObject("", 0) {};
    Folder(std::string name, int size): FileObject(name, size) {};
    
    void add_folder(std::string path, std::string folder_name);
    Folder* get_folder(std::string path, size_t depth, int size);
    void delete_folder(std::string path, std::string folder_name);

    void add_file(std::string path, std::string file_name, int size);
    File* get_file(std::string path, std::string file_name);
    std::list<File*> get_files(std::string path, std::string file_name);
    void get_files_inside(std::string file_name, AVL_Tree<File*> tree, std::list<File*> &file_list);
    void delete_file(std::string path, std::string file_name);

    friend std::ostream& operator<<(std::ostream &out, const Folder &folder);
};

#endif
