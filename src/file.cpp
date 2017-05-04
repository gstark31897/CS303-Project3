#include "file.h"

using namespace std;


std::ostream& operator<<(std::ostream &out, const File &file)
{   
    return out << file.getName();
}

