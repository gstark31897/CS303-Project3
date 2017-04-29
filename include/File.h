#ifndef H_FILE
#define H_FILE

#include "AVL_Tree.h"
#include "AVL_Node.h"

class File
{
private:
    std::string m_name;
    int m_size;
    
public:
    File();
    File(std::string name, int size);
    
    void add_file(std::string path, std::string file_name, int size);
    File get_file(std::string path, std::string file_name);
    list<File> get_files(std::string path, std::string file_name);
    void delete_file(std::string path, std::string file_name);
};

#endif

    
