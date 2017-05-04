#ifndef H_FILE
#define H_FILE

#include "fileobject.h"

#include "AVL_Tree.h"
#include "AVL_Node.h"

#include <list>


class File: public FileObject
{
private:
    std::string m_name;
    int m_size;
    
public:
    File(std::string name, int size): FileObject(name) { m_size = size; };

    void setSize(int size) { m_size = size; };
    int getSize() { return m_size; };

    friend std::ostream& operator<<(std::ostream &out, const File &file);
};

#endif

