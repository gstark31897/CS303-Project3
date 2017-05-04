#ifndef H_FILE
#define H_FILE

#include "AVL_Tree.h"
#include "AVL_Node.h"

#include <list>


class File
{
private:
    std::string m_name;
    int m_size;
    
public:
    File();
    File(std::string name, int size);

    void setSize(int size) { m_size = size; };
    int getSize() { return m_size; };

    friend std::ostream operator<<(std::ostream &out, const File &file);
};

#endif

