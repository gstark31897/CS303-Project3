#ifndef H_FILE
#define H_FILE

#include "fileobject.h"

#include "AVL_Tree.h"
#include "AVL_Node.h"

#include <list>


class File: public FileObject
{
private:
    
public:
    File(std::string name, int size): FileObject(name, size) {};

    friend std::ostream& operator<<(std::ostream &out, const File &file);
};

#endif

