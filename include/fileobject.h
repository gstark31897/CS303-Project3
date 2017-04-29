#ifndef H_FILEOBJECT
#define H_FILEOBJECT

#include <string>


class FileObject
{
private:
    std::string m_name;

public:
    FileObject(std::string name): m_name(name) {};

    std::string getName() { return m_name; };

    bool operator<(FileObject &other) { return m_name < other.getName(); };
    bool operator>(FileObject &other) { return m_name > other.getName(); };
};

#endif
